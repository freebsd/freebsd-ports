# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	bogged
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Word game for X Window System

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	> ${WRKDIR}/${PORTNAME}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/bogged

post-patch:
	@${REINPLACE_CMD} -e 's|wish|wish8.4|' ${WRKSRC}/bogged

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
