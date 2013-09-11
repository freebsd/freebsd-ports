# Created by: Igor Pokrovsky <tiamat@telegraph.spb.ru>
# $FreeBSD$

PORTNAME=	exult
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-all-versions/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultima VII engine

BUILD_DEPENDS=	timidity:${PORTSDIR}/audio/timidity
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_SDL=	sdl mixer
USE_XORG=	x11
USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

MAN1=	expack.1 ipack.1 shp2pcx.1 splitshp.1 textpack.1
MAN6=	exult.6

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|desktop||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
