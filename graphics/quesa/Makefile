# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	quesa
PORTVERSION=	1.8
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High level 3D graphics library compatible with Apple's QuickDraw(TM)

USES=		gl libtool xorg
USE_CXXSTD=	gnu++98
GNU_CONFIGURE=	yes
USE_GL=		glut
USE_XORG=	x11 ice xmu xi
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's|-std=c99||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|isfinite|finite|g' \
		${WRKSRC}/Source/Core/System/E3IOData.c \
		${WRKSRC}/Source/Core/System/E3View.c

.include <bsd.port.mk>
