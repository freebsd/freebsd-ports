# $FreeBSD$

PORTNAME=		Ice
PORTVERSION=		3.7.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=		devel
PKGNAMESUFFIX?=		37

MAINTAINER=		grembo@FreeBSD.org
COMMENT=		Modern alternative to object middleware such as CORBA/COM/DCOM/COM+

LICENSE=		GPLv2

SLAVE_PORT?=		no
CONFLICTS=		Ice py*-Ice php*-Ice

.if ${SLAVE_PORT} == "no"
LIB_DEPENDS=		libexpat.so:textproc/expat2 \
			liblmdb.so:databases/lmdb \
			libmcpp.so:devel/mcpp
.else
LIB_VRS=		${PORTVERSION:R:S|.||g}
LIB_DEPENDS+=		libIce.so.${LIB_VRS}:devel/ice37
PLIST_SUB+=		LIB_VERSION="${PORTVERSION}" LIB_VRS="${LIB_VRS}"
.endif

DESTDIRNAME=		NOT_USED # setting DESTDIR interferes with Ice's Makefiles

OPTIONS_DEFINE?=	DEBUG STATIC TEST
OPTIONS_SUB=		yes

USES+=			compiler:c++14-lang iconv gmake
CONFIGS=		shared
DEBUG_MAKE_ENV=		OPTIMIZE=no
TEST_ALL_TARGET_OFF=	srcs
MAKE_ARGS+=		V=1

CONFIGS=		shared

.if ${SLAVE_PORT} == "no"
USES+=			ssl
CONFIGS+=		cpp11-shared
STATIC_VARS=		configs+="static cpp11-static"
TEST_USES=		python:build shebangfix
TEST_VARS=		shebang_glob=*.py
TEST_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR}
.endif

.include <bsd.port.options.mk>

USE_LDCONFIG=		yes
BUILD_WRKSRC?=		${WRKSRC}/cpp
INSTALL_WRKSRC?=	${WRKSRC}/cpp
USE_GITHUB=		yes
GH_ACCOUNT=		zeroc-ice
GH_PROJECT=		ice

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV+=		LP64=yes
.endif

.include <bsd.port.pre.mk>

.if ${PREFIX} != ${LOCALBASE}
PYSITEDIR=		${PREFIX}${PYTHON_SITELIBDIR:S|^${LOCALBASE}||}
.else
PYSITEDIR=		${PYTHON_SITELIBDIR}
.endif

.if defined(PYTHON_VER) && (${PYTHON_VER} == "2.7" || ${PYTHON_VER} == "3.4")
PLIST_SUB+=		PYTHONGT34="@comment "
.else
PLIST_SUB+=		PYTHONGT34=""
.endif

post-patch:
	@${SED} 's|%%CONFIGS%%|${CONFIGS}|g; \
		s|%%DATADIR%%|${STAGEDIR}${DATADIR}|g; \
		s|%%DOCSDIR%%|${STAGEDIR}${DOCSDIR}|g; \
		s|%%ICONV_LIB%%|${ICONV_LIB}|g; \
		s|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%MANPREFIX%%|${STAGEDIR}${MANPREFIX}|g; \
		s|%%OPENSSLLIB%%|${OPENSSLLIB}|g; \
		s|%%OPENSSLINC%%|${OPENSSLINC}|g; \
		s|%%PREFIX%%|${STAGEDIR}${PREFIX}|g;' \
		${FILESDIR}/Make.rules.FreeBSD > ${WRKSRC}/config/Make.rules.FreeBSD
	@${REINPLACE_CMD} 's|%%CHMOD%%|${CHMOD}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%INSTALL_LIB%%|${INSTALL_LIB}|g; \
		s|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%MKDIR%%|${MKDIR}|g; \
		s|%%MV%%|${MV}|g; \
		s|%%RM%%|${RM}|g;' \
		${WRKSRC}/config/Make.project.rules
	@${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%ICONV_LIB%%|${ICONV_LIB}|g; \
		s|%%PYTHON_CMD%%|${PYTHON_CMD}|g; \
		s|%%PYTHON_SITELIBDIR%%|${STAGEDIR}${PYSITEDIR}|g; \
		s|%%PREFIX%%|${PREFIX}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/python/config/Make.rules
	@${REINPLACE_CMD} 's|%%CHMOD%%|${CHMOD}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%INSTALL_LIB%%|${INSTALL_LIB}|g; \
		s|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%MKDIR%%|${MKDIR}|g; \
		s|%%MV%%|${MV}|g; \
		s|%%RM%%|${RM}|g;' \
		${WRKSRC}/python/python/Makefile
	@${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%PREFIX%%|${PREFIX}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g;' ${WRKSRC}/php/Makefile
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g;' \
		${WRKSRC}/scripts/Util.py
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g;' \
		${WRKSRC}/scripts/Glacier2Util.py

IS_JAILED_CMD=		${SYSCTL} -n security.jail.jailed
JAILED_FILTER=		--rfilter=IceDiscovery \
			--rfilter=priority \
			--rfilter=threadPoolPriority \
			--rfilter=udp

do-test-TEST-on:
.for CONFIG in ${CONFIGS}
	@${ECHO} Testing configuration ${CONFIG}
	cd ${BUILD_WRKSRC} && \
		${SETENV} LC_ALL=en_US.UTF-8 ${PYTHON_CMD} ./allTests.py \
		--config=${CONFIG} \
		$$(${TEST} $$(${IS_JAILED_CMD}) -eq 1 \
			&& ${ECHO} ${JAILED_FILTER})
.endfor

.if ${SLAVE_PORT} == "no"

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*
	@cd ${WRKSRC} && ${GMAKE} install-doc install-slice
.endif

.include <bsd.port.post.mk>
