# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freeciv
PORTVERSION=	3
CATEGORIES=	games
MASTER_SITES=	GENTOO \
		ftp://ftp.freeciv.org/freeciv/contrib/audio/soundsets/
PKGNAMESUFFIX=	-sounds
DISTNAME=	stdsounds${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Freeciv standard sound set

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/data
NO_ARCH=	yes

do-install:
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
