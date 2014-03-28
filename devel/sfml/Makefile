# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sfml
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	SFML-${PORTVERSION}-sdk-linux-32

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

PORTDOCS=	*

PORTSCOUT=	limit:[^c]$$

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} -f ${WRKSRC}/lib/*
	@${FIND} ${WRKSRC}/samples/bin/ -type f -maxdepth 1 -delete

post-install:
.for lib in audio graphics network system window
	@${LN} -s libsfml-${lib}.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libsfml-${lib}.so.${PORTVERSION:C/^([0-9]).*/\1/}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
