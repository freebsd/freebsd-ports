# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnatcoll
PORTVERSION=	2014
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	${PORTNAME}-gpl-${PORTVERSION}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNAT Component Collection from Adacore

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild>=20120510:${PORTSDIR}/devel/gprbuild \
		gnat_util>=20140422:${PORTSDIR}/lang/gnat_util
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

USES=		ada gmake
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm
PORTDOCS=	html gnatcoll.pdf
PORTEXAMPLES=	*

OPTIONS_DEFINE=		READLINE SYSLOG SQLITE PYTHON GTK PGSQL ICONV \
			DOCS EXAMPLES
OPTIONS_DEFAULT=	READLINE SYSLOG SQLITE PYTHON GTK PGSQL
OPTIONS_SUB=		yes
DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
GTK_LIB_DEPENDS=	libgtkada.so:${PORTSDIR}/x11-toolkits/gtkada3
SYSLOG_CONFIGURE_ENABLE=syslog

GTK_DESC=		GTK3 toolkit support

CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-aux-${OPSYS:tl}${OSREL}
CONFIGURE_ARGS=		--with-gmp=${PREFIX} \
			--disable-shared \
			--disable-pygtk

MAKE_ARGS+=		PROCESSORS=${MAKE_JOBS_NUMBER}
MAKE_ARGS+=		Gnatcoll_Build=Production

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE}
USES+=			readline:port
CONFIGURE_ARGS+=	--enable-gpl
.else
CONFIGURE_ARGS+=	--disable-readline
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--with-sqlite=embedded
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=			pgsql
CONFIGURE_ARGS+=	--with-postgresql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

# There might be something wrong with iconv support as seen in GPS crash.
# That's why this option is not enabled by default
.if ${PORT_OPTIONS:MICONV}
USES+=			iconv
CONFIGURE_ARGS+=	--with-iconv=${ICONV_PREFIX}
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python=${PREFIX} \
			--enable-pygobject
USE_PYTHON=		yes
USE_GNOME=		pygobject3
PYCOMPILE=		${PREFIX}/lib/${PYTHON_VERSION}/compileall.py
.else
CONFIGURE_ARGS+=	--without-python \
			--disable-pygobject
.endif

.if ${PORT_OPTIONS:MGTK}
USES+=			pkgconfig
CONFIGURE_ARGS+=	--with-gtk=3.0
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|@PREFIX@|${PREFIX}|g" \
	    ${WRKSRC}/src/gnatcoll_readline.gpr.in
.if ! ${PORT_OPTIONS:MDOCS}
	${MV} ${WRKSRC}/docs/_build ${WRKSRC}/docs/_hide_build
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	${RM} -rf ${STAGEDIR}${DOCSDIR}/html/_sources
	${RM} -rf ${STAGEDIR}${PREFIX}/share/gps
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${RM} -rf ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MSQLITE}
	# Rename gnatinspect to gnatinspect-xref to avoid GPS conflict
	cd ${STAGEDIR}${PREFIX}/bin && ${MV} gnatinspect gnatinspect-xref
.endif

.include <bsd.port.mk>
