# $FreeBSD$

PORTNAME=	animenfo
PORTVERSION=	20020819
CATEGORIES=	databases
MASTER_SITES=	http://www.animenfo.com/extension/files/
PKGNAMESUFFIX=	-client${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-client
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	AnimeNfo client

LICENSE=	GPLv2

USE_GMAKE=	yes
PLIST_FILES=	bin/animenfo-client

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/animenfo-client ${PREFIX}/bin/

.include <bsd.port.mk>
