# Created by: Arun Sharma <arun@sharma-home.net>
# $FreeBSD$

PORTNAME=	tbb
PORTVERSION=	2017.7
CATEGORIES=	devel

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Library that provides thread building blocks

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	01org
GH_TAGNAME=	${PORTVERSION:S/./_U/}

SUB_FILES=	tbb.pc
SUB_LIST=	prefix="${PREFIX}" \
		name="${PORTNAME}" \
		description="${COMMENT}" \
		version="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

ONLY_FOR_ARCHS=		amd64 i386 armv6
ONLY_FOR_ARCHS_REASON=	has not been ported to this platform

USE_LDCONFIG=	yes
USES=	compiler gmake tar:tgz
ALL_TARGET=	default

CC_BASENAME=	${CC:C,^.*/,,}

.include <bsd.port.pre.mk>

post-extract:
.if ${CC_BASENAME} != ${COMPILER_TYPE}
	@${LN} -sf FreeBSD.${COMPILER_TYPE}.inc ${WRKSRC}/build/FreeBSD.${CC_BASENAME}.inc
.endif
	@${CP} ${FILESDIR}/version_info_FreeBSD.sh ${WRKSRC}/build/

post-patch:
	@${REINPLACE_CMD} \
		-e '/^CONLY =/s|^CONLY =.*|CONLY = ${CC}|' \
		-e '/^CPLUS =/s|^CPLUS =.*|CPLUS = ${CXX}|' \
			${WRKSRC}/build/FreeBSD.${COMPILER_TYPE}.inc

do-install:
	cd ${WRKSRC}; \
	${INSTALL_LIB} build/FreeBSD*release/libtbb.so \
		${STAGEDIR}${PREFIX}/lib/libtbb.so.2; \
	${LN} -sf libtbb.so.2 \
		${STAGEDIR}${PREFIX}/lib/libtbb.so; \
	${INSTALL_LIB} build/FreeBSD*release/libtbbmalloc.so \
		${STAGEDIR}${PREFIX}/lib/libtbbmalloc.so.2; \
	${LN} -sf libtbbmalloc.so.2 \
		${STAGEDIR}${PREFIX}/lib/libtbbmalloc.so; \
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tbb/; \
	cd include/tbb/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/tbb/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/tbb.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.post.mk>
