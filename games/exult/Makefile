# New ports collection makefile for:	exult
# Date created:		18 February 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	exult
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Ultima VII engine

BUILD_DEPENDS=	timidity:${PORTSDIR}/audio/timidity
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_XLIB=	yes
USE_SDL=	sdl mixer
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	expack.1 ipack.1 shp2pcx.1 splitshp.1 textpack.1
MAN6=	exult.6

post-patch:
	@${REINPLACE_CMD} -e 's|desktop||' ${WRKSRC}/Makefile.in

post-install:
.ifndef	(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${SED} -e 's|%%DOCSDIR%%|${DOCSDIR}|' <${PKGMESSAGE}

.include <bsd.port.mk>
