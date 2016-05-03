# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnatcoll
PORTVERSION=	2015
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	${PORTNAME}-gpl-${PORTVERSION}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNAT Component Collection from Adacore

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild>=20120510:devel/gprbuild \
		gnat_util>=20140422:lang/gnat_util
LIB_DEPENDS=	libgtkada.so:x11-toolkits/gtkada3 \
		libgmp.so:math/gmp
RUN_DEPENDS=	gnat_util>=20140422:lang/gnat_util

USES=		ada gmake pkgconfig python
USE_GNOME=	pygobject3
PYCOMPILE=	${PREFIX}/lib/${PYTHON_VERSION}/compileall.py
GNU_CONFIGURE=	yes
PORTDOCS=	html gnatcoll.pdf
PORTEXAMPLES=	*

MAKE_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER} \
		Gnatcoll_Build=Production

OPTIONS_DEFINE=		READLINE SYSLOG PGSQL ICONV DOCS EXAMPLES
OPTIONS_DEFAULT=	READLINE SYSLOG
OPTIONS_SUB=		yes
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
SYSLOG_CONFIGURE_ENABLE=	syslog

CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-aux-${OPSYS:tl}${OSREL}
CONFIGURE_ARGS=		--with-gmp=${PREFIX} \
			--with-sqlite=embedded \
			--with-python=${PREFIX} \
			--with-gtk=3.0 \
			--enable-pygobject \
			--disable-shared \
			--disable-pygtk

.include <bsd.port.options.mk>

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

# There might be something wrong with iconv support as seen in GPS crash.
# That's why this option is not enabled by default
.if ${PORT_OPTIONS:MICONV}
USES+=			iconv
CONFIGURE_ARGS+=	--with-iconv=${ICONV_PREFIX}
.else
CONFIGURE_ARGS+=	--without-iconv
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
	${RM} -r ${STAGEDIR}${DOCSDIR}/html/_sources
	${RM} -r ${STAGEDIR}${PREFIX}/share/gps
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}/library
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
