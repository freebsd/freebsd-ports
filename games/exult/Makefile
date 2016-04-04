# Created by: Igor Pokrovsky <tiamat@telegraph.spb.ru>
# $FreeBSD$

PORTNAME=	exult
PORTVERSION=	1.5.0.20130315
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.math.leidenuniv.nl/~wpalenst/cvs/
DISTNAME=	exult-20130315-0400

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultima VII engine

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	timidity:audio/timidity
RUN_DEPENDS=	timidity:audio/timidity

USE_SDL=	sdl mixer
USE_XORG=	x11
USES=		autoreconf gmake libtool pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/exult

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	STUDIO
OPTIONS_DEFAULT=STUDIO
OPTIONS_SUB=	yes
STUDIO_DESC=	Install Exult Studio

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTUDIO}
CONFIGURE_ARGS+=--enable-exult-studio \
		--enable-exult-studio-support
USE_GNOME+=	libglade2
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
