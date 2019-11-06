# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	hohlin
PORTVERSION=	1.01
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://retrospec.sgn.net/games/hoh/bin/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${SHORTPORTVERSION}

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Remake of the classic spectrum game Head over Heels

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/hoh-install-${PORTVERSION}/

USES=		linux tar:bzip2
USE_LINUX=	xorglibs
ONLY_FOR_ARCHS=	i386 amd64
SHORTPORTVERSION=${PORTVERSION:C/([0-9]*)\.([0-9]*)/\1\2/}

OPTIONS_DEFINE=	DOCS

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/data/HoH

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/data/HoH ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/HoHOriginal.dat ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/Sound
	${INSTALL_DATA} ${WRKSRC}/data/Sound/Sound.dat ${STAGEDIR}${DATADIR}/Sound/
	${INSTALL_DATA} ${WRKSRC}/data/Sound/Game.ogg ${STAGEDIR}${DATADIR}/Sound/
	${INSTALL_DATA} ${WRKSRC}/data/Sound/Theme.ogg ${STAGEDIR}${DATADIR}/Sound/
	${SED} -e 's:%%DATADIR%%:${DATADIR}:g' ${FILESDIR}/hoh.sh > \
		${STAGEDIR}${PREFIX}/bin/HoH
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/HoH
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
