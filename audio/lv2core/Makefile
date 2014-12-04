# Created by: xaimus <xaimus@gmail.com>
# $FreeBSD$

PORTNAME=	lv2core
PORTVERSION=	6.0
CATEGORIES=	audio
MASTER_SITES=	http://lv2plug.in/spec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LV2 Core Package

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig python:build tar:bzip2

.include <bsd.port.pre.mk>

.if defined(BATCH) || defined(PACKAGE_BUILDING)
WAF_VERBOSE=	--verbose
.endif

WAF_JOBS=	--jobs=${MAKE_JOBS_NUMBER}

post-patch:
	@${REINPLACE_CMD} -e '/autowaf.build_pc/s|^|#|' ${WRKSRC}/wscript
	@(cd ${WRKSRC} && ${SED} -e \
		's|@PREFIX@|${PREFIX}| ; \
		 s|@EXEC_PREFIX@|${PREFIX}| ; \
		 s|@LIBDIR@|${PREFIX}/lib| ; \
		 s|@INCLUDEDIR@|${PREFIX}/include| ; \
		 s|@LV2CORE_VERSION@|${PORTVERSION}|' < lv2core.pc.in > lv2core.pc)

do-configure:
	@(cd ${WRKSRC} && ${PYTHON_CMD} waf ${WAF_VERBOSE} --prefix=${PREFIX} configure)

do-build:
	@(cd ${WRKSRC} && ${PYTHON_CMD} waf ${WAF_VERBOSE} ${WAF_JOBS} build)

do-install:
	@(cd ${WRKSRC} && ${PYTHON_CMD} waf --destdir=${STAGEDIR} \
		${WAF_VERBOSE} install)
	${INSTALL_DATA} ${WRKSRC}/lv2core.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.post.mk>
