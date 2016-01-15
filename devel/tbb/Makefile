# Created by: Arun Sharma <arun@sharma-home.net>
# $FreeBSD$

PORTNAME=	tbb
PORTVERSION=	4.4.2
CATEGORIES=	devel
MASTER_SITES=	http://threadingbuildingblocks.org/sites/default/files/software_releases/source/ \
		LOCAL/martymac
DISTNAME=	${PORTNAME}${PORTVERSION:R:S/.//g}_20151115oss_src

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Library that provides thread building blocks

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	has not been ported to this platform

USE_LDCONFIG=	yes
USES=	compiler gmake tar:tgz
ALL_TARGET=	default

WRKSRC=	${WRKDIR}/${DISTNAME:S/_src//}

.include <bsd.port.pre.mk>

post-extract:
.if ${CC} != "gcc"
	@${CP} ${WRKSRC}/build/FreeBSD.gcc.inc ${WRKSRC}/build/FreeBSD.${CC}.inc
.endif
	@${CP} ${FILESDIR}/version_info_FreeBSD.sh ${WRKSRC}/build/

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' -e 's|g++|${CXX}|g' \
		${WRKSRC}/build/FreeBSD.${CC}.inc
.if ${COMPILER_TYPE} != "gcc"
	@${REINPLACE_CMD} -e 's| -fno-schedule-insns2||g' \
		${WRKSRC}/build/FreeBSD.${CC}.inc
.endif

do-install:
	cd ${WRKSRC}; \
	${INSTALL_LIB} build/FreeBSD*release/libtbb.so \
		${STAGEDIR}${PREFIX}/lib/libtbb.so.4; \
	${LN} -sf ${PREFIX}/lib/libtbb.so.4 \
		${STAGEDIR}${PREFIX}/lib/libtbb.so; \
	${INSTALL_LIB} build/FreeBSD*release/libtbbmalloc.so \
		${STAGEDIR}${PREFIX}/lib/libtbbmalloc.so.4; \
	${LN} -sf ${PREFIX}/lib/libtbbmalloc.so.4 \
		${STAGEDIR}${PREFIX}/lib/libtbbmalloc.so; \
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tbb/; \
	cd include/tbb/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/tbb/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
