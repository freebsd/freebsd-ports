# New ports collection makefile for:	exult
# Date created:		18 February 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	exult
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-all-versions/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultima VII engine

BUILD_DEPENDS=	timidity:${PORTSDIR}/audio/timidity
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_SDL=	sdl mixer
USE_XORG=	x11
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	expack.1 ipack.1 shp2pcx.1 splitshp.1 textpack.1
MAN6=	exult.6

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|desktop||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
