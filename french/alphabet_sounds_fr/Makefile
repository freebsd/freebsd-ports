# Created by: bruno
# $FreeBSD$

PORTNAME=	alphabet_sounds_fr
PORTVERSION=	0.3
PORTREVISION=	11
CATEGORIES=	french games
MASTER_SITES=	SF/childsplay/OldFiles
DISTNAME=	alphabet_sounds_fr

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	Educative games for children. Alphabet sounds package (french)

BUILD_DEPENDS=	${LOCALBASE}/bin/childsplay:${PORTSDIR}/games/childsplay
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s@PREFIX=/usr/local@PREFIX=${PREFIX}@g " ${WRKSRC}/install.sh

.include <bsd.port.mk>
