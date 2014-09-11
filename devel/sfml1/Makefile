# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sfml
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	SFML-${PORTVERSION}-sdk-linux-32
PKGNAMESUFFIX=	1

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple and Fast Multimedia Library

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		gmake openal:al pkgconfig dos2unix
DOS2UNIX_GLOB=	Makefile
USE_XORG=	x11 xrandr
USE_GL=		gl glu
USE_LDCONFIG=	yes
DESTDIRNAME=	STAGEDIR

WRKSRC=		${WRKDIR}/SFML-${PORTVERSION}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	*

PORTSCOUT=	limit:[^c]$$

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} -f ${WRKSRC}/lib/*
	@${FIND} ${WRKSRC}/samples/bin/ -type f -maxdepth 1 -delete

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/include/SFML -name "*.hpp" -exec ${REINPLACE_CMD} -i '' -e '/#include/ s|SFML|&1|' {} \;
	${MV} ${STAGEDIR}${PREFIX}/include/SFML ${STAGEDIR}${PREFIX}/include/SFML${PKGNAMESUFFIX}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
