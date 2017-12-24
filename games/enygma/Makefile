# Created by: Wouter Reckman <gennerate@zonnet.nl>
# $FreeBSD$

PORTNAME=	enygma
PORTVERSION=	1.04
CATEGORIES=	games
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/enigma/
DISTNAME=	enigma-${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-based puzzle game

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		localbase ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games
CPPFLAGS+=	-I${NCURSESINC}

.include <bsd.port.mk>
