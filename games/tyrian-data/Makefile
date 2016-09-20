# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tyrian-data
PORTVERSION=	21
CATEGORIES=	games
MASTER_SITES=	http://www.camanis.net/tyrian/ \
		http://sites.google.com/a/camanis.net/opentyrian/tyrian/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	tyrian${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Data files for opentyrian

# From opentyrian FAQ:
# "Tyrian was, however, released as freeware (under no specific
# license) by Jason Emery in August 2004"
LICENSE=	NONE

USES=		zip

DATADIR=	${PREFIX}/share/tyrian

PORTDATA=	*

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
