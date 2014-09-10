# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gps
PORTVERSION=	6.1.0.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
PKGNAMESUFFIX=	-ide

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNAT Programming Studio - IDE for Ada and many other languages

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild>=20140417:${PORTSDIR}/devel/gprbuild \
		gnat_util>=20140422_2:${PORTSDIR}/lang/gnat_util \
		xmlada>=4.4:${PORTSDIR}/textproc/xmlada \
		templates_parser>11:${PORTSDIR}/textproc/templates_parser
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libgtkada.so:${PORTSDIR}/x11-toolkits/gtkada3

GNU_CONFIGURE=		yes
USES=			ada gmake perl5 pkgconfig tar:bzip2
USE_PERL5=		build
USE_GNOME=		glib20
USE_PYTHON=		yes
USE_GNOME=		pygobject3
PYCOMPILE=		${PREFIX}/lib/${PYTHON_VERSION}/compileall.py
AWKREVDATE=		'/Last Changed Date/ {print "\"s|unknown date|" $$4 "|\""}'
GPSVER=			GPS_VERSION=${PORTVERSION}
ALL_TARGET=		default
NO_MTREE=		yes

OPTIONS_DEFINE=		READLINE SYSLOG PGSQL DEBUG DOCS EXAMPLES
OPTIONS_DEFAULT=	READLINE SYSLOG
OPTIONS_SUB=		yes
DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
SYSLOG_CONFIGURE_ENABLE=syslog

CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-aux-${OPSYS:tl}${OSREL}
CONFIGURE_ENV+=		AWK=/usr/bin/awk
CONFIGURE_ARGS=		--with-gmp=${PREFIX} \
			--with-gtk=3.0 \
			--with-sqlite=embedded \
			--with-python=${PREFIX} \
			--enable-pygobject \
			--disable-shared \
			--disable-pygtk
MAKE_ARGS+=		PROCESSORS=${MAKE_JOBS_NUMBER}
MAKE_ARGS+=		PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=		Build=Debug
.else
MAKE_ARGS+=		Build=Production
.endif

.if ${PORT_OPTIONS:MREADLINE}
USES+=			readline:port
CONFIGURE_ARGS+=	--enable-gpl
.else
CONFIGURE_ARGS+=	--disable-readline
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=			pgsql
CONFIGURE_ARGS+=	--with-postgresql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

# Iconv option crashes GPS almost immediately.
# GNATColl needs to be examined before attempting to support Iconv again
.if 0 #${PORT_OPTIONS:  MICONV}
USES+=			iconv
CONFIGURE_ARGS+=	--with-iconv=${ICONV_PREFIX}
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

post-extract:
	@${MV} ${WRKSRC}/templates_parser ${WRKSRC}/TP.ignore
	@${MV} ${WRKSRC}/Makefile.gnat ${WRKSRC}/Makefile.gnat.ignore

post-patch:
	@${ECHO} "GNAT_SOURCES=" > ${WRKSRC}/Makefile.gnat
	@${REINPLACE_CMD} -e 's/^with .*templates_parser\//with "/g' \
		${WRKSRC}/docgen2/docgen2.gpr \
		${WRKSRC}/gnatdoc/gnatdoc.gpr \
		${WRKSRC}/vcs/vcs.gpr
	@${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' \
		${WRKSRC}/gnatlib/src/gnatcoll_readline.gpr.in \
		${WRKSRC}/widgets/widgets.gpr
	@${REINPLACE_CMD} -e 's| gnat/sdefault/sdefault.adb | |' \
		-e 's;freebsd;freebsd*|*-dragonfly;g' \
		${WRKSRC}/gnatlib/configure \
		${WRKSRC}/gnatlib/configure.in
	@${REINPLACE_CMD} -e 's|gnatlib/gnat_src|distrib|' \
		${WRKSRC}/distrib/from_impunit.pl
	@${REINPLACE_CMD} -e 's|, "-fdump-xref"||g' \
		${WRKSRC}/gnatlib/gnatcoll_shared.gpr.in \
		${WRKSRC}/shared.gpr
	@${REINPLACE_CMD} -e "s|GPS_VERSION=.*|${GPSVER}|" \
		${WRKSRC}/configure
	@${AWK} ${AWKREVDATE} ${WRKSRC}/REVISION | ${XARGS} -I sub \
		${SED} -i.bak -e sub ${WRKSRC}/common/core/src/config.ads.in

do-build:
	@${CP} ${PREFIX}/include/gnat_util/impunit.* ${WRKSRC}/distrib
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} all
	${PYTHON_CMD} ${PYCOMPILE} ${WRKSRC}/share/plug-ins
	${PYTHON_CMD} ${PYCOMPILE} ${WRKSRC}/share/library

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/doc/gps/html/users_guide/_sources
	${RM} -rf ${STAGEDIR}${PREFIX}/share/doc/gps/html/tutorial/_sources
	echo "This is the GPS GPL Edition for the FreeBSD Ports Collection." \
		> ${STAGEDIR}${PREFIX}/share/gps/about.txt
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d -empty -print | ${XARGS} ${RMDIR}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e '/share\/doc$$/d' -e '/share\/gps$$/d' \
	   -e '/share\/gps\/plug-ins$$/d' -e '/share\/examples$$/d' \
	   -e 's/^/@dirrm /g' >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps/plug-ins 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
