# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	freedoom
DISTVERSION=	0.11.3
CATEGORIES=	games
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Complete Doom-based game IWAD that is Free Software

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${DMDIR}/${PORTNAME}

PLIST_FILES=	${DATADIR}/freedoom1.wad \
		${DATADIR}/freedoom2.wad

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/freedoom1.wad ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/freedoom2.wad ${STAGEDIR}${DATADIR}

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
