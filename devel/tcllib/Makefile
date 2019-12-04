# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	tcllib
PORTVERSION=	1.20
CATEGORIES=	devel tcl
MASTER_SITES=	https://core.tcl.tk/tcllib/uv/

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Collection of utility modules for Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE?=DOCS MANPAGES
OPTIONS_SUB=	yes

USES+=		tcl tar:xz
USE_LOCALE=	en_US.UTF-8
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_tclsh="${TCLSH}"
TEST_TARGET=	test
TEST_ENV=	${MAKE_ENV} DISPLAY= TZ=utc

.if ${OPTIONS_DEFINE:MDOCS}
PORTDOCS=	*
.endif

INSTALL_ARGS=	-pkgs -pkg-path ${STAGEDIR}${PREFIX}/lib/tcllib \
		-apps -app-path ${STAGEDIR}${PREFIX}/bin \
		-no-wait -no-gui -no-examples

.include <bsd.port.options.mk>

#
# Man pages
#
.if ${PORT_OPTIONS:MMANPAGES} && !(defined(ALL_TARGET) && !empty(ALL_TARGET:Mcritcl))
ALL_TARGET+=	nroff-doc
INSTALL_ARGS+=	-nroff-path ${STAGEDIR}${PREFIX}/man/mann
.else
INSTALL_ARGS+=	-no-nroff
.endif

#
# HTML documentation
#
.if ${PORT_OPTIONS:MDOCS} && !(defined(ALL_TARGET) && !empty(ALL_TARGET:Mcritcl))
ALL_TARGET+=	html-doc
INSTALL_ARGS+=	-html-path ${STAGEDIR}${DOCSDIR}
.else
INSTALL_ARGS+=	-no-html
.endif

.if !target(post-patch)
post-patch:
#
#	Ensure the detailed output of vendors' self-tests is
#	available in addition to the pretty progress report:
#
	${REINPLACE_CMD} -e 's,test run,test run -l testlog,' \
		-e 's,$$(libdir)/@PACKAGE@@VERSION@,$$(libdir)/@PACKAGE@,' \
		${WRKSRC}/Makefile.in
	${FIND} ${WRKSRC}/apps -type f ! -name "*.man" | ${XARGS} \
	   ${REINPLACE_CMD} -e 's,exec tclsh,exec ${TCLSH},' -e 's,/usr/bin/env tclsh,${TCLSH},'
#
#	man pages have the .tcllib suffix, so there's no need to have a
#	tcllib_ prefix too
#
	cd ${WRKSRC} && \
	for man in `${FIND} . -name "tcllib_*.man"`; do \
	    ${MV} $$man `echo $$man | ${SED} -e 's|tcllib_||'`; \
	done && \
	for man in `${FIND} . -name "tcllib_*.n"`; do \
	    ${MV} $$man `echo $$man | ${SED} -e 's|tcllib_||'`; \
	done

#
#	add the .tcllib suffix to man pages
#
	cd ${WRKSRC} && \
	for man in `${FIND} . -name "*.man"`; do \
	    ${MV} $$man `echo $$man | ${SED} -e 's|man$$|tcllib.man|'`; \
	done && \
	for man in `${FIND} . -name "*.n"`; do \
	    ${MV} $$man `echo $$man | ${SED} -e 's|n$$|tcllib.n|'`; \
	done

#
#	remove all .orig files
#
#	${FIND} ${WRKSRC} -type f -name "*.orig" -delete
.endif

.if !target(do-install)
do-install:
	cd ${WRKSRC} && ${TCLSH} ./installer.tcl ${INSTALL_ARGS}
.endif

.include <bsd.port.mk>
