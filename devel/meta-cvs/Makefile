# Created by: johs
# $FreeBSD$

PORTNAME=	meta-cvs
PORTVERSION=	1.1.98
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/meta-cvs/downloads/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	More capable version control system than CVS, built around CVS

LICENSE=	GPLv2

DEPRECATED=	Depends on deprecated lang/clisp
EXPIRATION_DATE=	2014-07-28

BUILD_DEPENDS=	clisp:${PORTSDIR}/lang/clisp \
    		lndir:${PORTSDIR}/devel/lndir
RUN_DEPENDS=	clisp:${PORTSDIR}/lang/clisp

OPTIONS_DEFINE=	DOCS

USES=		gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/mcvs \
		bin/mcvs-debug \
		${DATADIR:C/${PREFIX}\///}/mcvs.mem \
		${DATADIR:C/${PREFIX}\///}/mcvs-debug.mem
PLIST_DIRS=	${DATADIR:C/${PREFIX}\///}

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
#	libc.so is now a symlink, let's find out the real name of the libc
#	shared library. See:
#	http://svnweb.freebsd.org/base/head/lib/libc/libc.ldscript?revision=251668&view=markup
	rep=$$(${BASENAME} $$(${LDCONFIG} -r | ${AWK} '/libc.so/ { print $$3 }')); \
	    ${REINPLACE_CMD} -e "s|libc.so.6|$$rep|" ${WRKSRC}/code/clisp-ffi.lisp
	${REINPLACE_CMD} -e '232s|make|${GMAKE}|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|type -P|which|g;s|$$(prefix)/lib|${DATADIR}|g' ${WRKSRC}/Makefile

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	latex:build
post-build:
	cd ${WRKSRC}/docs/tex-manual && \
	    pdflatex meta-cvs.latex && \
	    pdflatex meta-cvs.latex && \
	    pdflatex meta-cvs.latex
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mcvs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mcvs-debug ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mcvs.mem ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mcvs-debug.mem ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/misc-text-files/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/tex-manual/*.pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
