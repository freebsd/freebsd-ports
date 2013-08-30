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

LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

USES=		gmake pkgconfig
USE_OPENAL=	al
USE_XORG=	x11 xrandr
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_DOS2UNIX=	Makefile

WRKSRC=		${WRKDIR}/SFML-${PORTVERSION}

PORTDOCS=	*

PORTSCOUT=	limit:[^c]$$

.include <bsd.port.options.mk>

post-extract:
	@${RM} -f ${WRKSRC}/lib/*
	@${FIND} ${WRKSRC}/samples/bin/ -type f -maxdepth 1 -delete

post-install:
.for lib in audio graphics network system window
	@${LN} -s libsfml-${lib}.so.${PORTVERSION} ${PREFIX}/lib/libsfml-${lib}.so.${PORTVERSION:C/^([0-9]).*/\1/}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "*" ${DOCSDIR}/
.endif

.include <bsd.port.mk>
