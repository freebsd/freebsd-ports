# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sfml
PORTVERSION=	1.6
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF
PKGNAMESUFFIX=	1
DISTNAME=	SFML-${PORTVERSION}-sdk-linux-32

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple and Fast Multimedia Library

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USES=		gmake jpeg gl openal:al pkgconfig dos2unix xorg
DOS2UNIX_GLOB=	Makefile ResourcePtr.inl
USE_XORG=	x11 xrandr
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_CXXSTD=	c++98
DESTDIRNAME=	STAGEDIR

WRKSRC=		${WRKDIR}/SFML-${PORTVERSION}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	*

PORTSCOUT=	limit:[^c]$$

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/lib/*
	@${FIND} ${WRKSRC}/samples/bin/ -type f -maxdepth 1 -delete

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/include/SFML -name "*.hpp" -exec ${REINPLACE_CMD} -i '' -e '/#include/ s|SFML|&1|' {} \;
	@${MV} ${STAGEDIR}${PREFIX}/include/SFML ${STAGEDIR}${PREFIX}/include/SFML${PKGNAMESUFFIX}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
