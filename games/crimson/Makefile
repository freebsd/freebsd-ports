# New ports collection makefile for:	crimson
# Date created:				3 May 2001
# Whom:					Jan Jungnickel <jan@jungnickel.com>
#
# $FreeBSD$

PORTNAME=	crimson
PORTVERSION=	0.1.3
CATEGORIES=	games
MASTER_SITES=	http://www.lanipage.de/jens/crimson/
PKGNAMESUFFIX=	-fields
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jan@jungnickel.com

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s|sdl-config|sdl11-config|; s|SDL/|SDL11/|" \
		${WRKSRC}/configure

.include <bsd.port.mk>
