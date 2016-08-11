# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnatcoll
PORTVERSION=	2016	# branch: gpl-for-gps-2016
CATEGORIES=	devel

MAINTAINER=	marino@FreeBSD.org
COMMENT=	GNAT Component Collection from Adacore

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild:devel/gprbuild \
		gnat_util>=20140422:lang/gnat_util
LIB_DEPENDS=	libgtkada.so:x11-toolkits/gtkada3 \
		libgmp.so:math/gmp
RUN_DEPENDS=	gnat_util>=20140422:lang/gnat_util

USES=		ada gmake pkgconfig python
USE_GNOME=	pygobject3
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_PROJECT=	gprbuild:libgpr
GH_TAGNAME=	858f72c a2e9066:libgpr

PYCOMPILE=	${PREFIX}/lib/${PYTHON_VERSION}/compileall.py
GNU_CONFIGURE=	yes
ALL_TARGET=	all
PORTDOCS=	*
PORTEXAMPLES=	*

MAKE_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER} \
		Gnatcoll_Build=Production

OPTIONS_DEFINE=		READLINE SYSLOG PGSQL DOCS EXAMPLES
OPTIONS_DEFAULT=	READLINE SYSLOG
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_ALL_TARGET=	docs
SYSLOG_CONFIGURE_ENABLE=	syslog

CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-aux-${OPSYS:tl}${OSREL}
CONFIGURE_ARGS=		--with-gmp=${PREFIX} \
			--with-sqlite=embedded \
			--with-python_exec=${PYTHON_CMD} \
			--with-gtk=3.0 \
			--without-iconv \
			--enable-pygobject \
			--enable-projects \
			--disable-shared \
			--disable-pygtk

READLINE_USES=		readline:port
READLINE_CONFIGURE_ON=	--enable-gpl
READLINE_CONFIGURE_OFF=	--disable-readline

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-postgresql=${PREFIX}
PGSQL_CONFIGURE_OFF=	--without-postgresql

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|@PREFIX@|${PREFIX}|g" \
	    ${WRKSRC}/src/gnatcoll_readline.gpr.in
	@${REINPLACE_CMD} -e 's|with "gpr"|with "${WRKSRC_libgpr}/gpr/gpr"|' \
		${WRKSRC}/src/gnatcoll__libgpr.gpr

pre-build:
	(cd ${WRKSRC_libgpr}/gpr && ${SETENV} ${MAKE_ENV} \
		gprbuild -p -P gpr);

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gnatcoll_db2ada
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gnatinspect
	${RM} -r ${STAGEDIR}${DOCSDIR}/html/_sources
	${RM} -r ${STAGEDIR}${PREFIX}/share/gps
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}/library
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
