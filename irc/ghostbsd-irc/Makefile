# New ports collection makefile for: ghostbsd-irc client
# Date created:        17 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-irc
PORTVERSION=	1.3
CATEGORIES=	irc

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD irc client 

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes
RUN_DEPENDS=	ssft.sh:devel/ssft\
		dpkg:archivers/dpkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ghostbsd-irc ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ghostbsd-irc.desktop ${STAGEDIR}/${PREFIX}/share/applications
	${CP}    ${WRKSRC}/icons/pixmaps/* ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} -p ${STAGEDIR}${PREFIX}/share/icons/hicolor
	${CP} -R ${WRKSRC}/icons/hicolor/* ${STAGEDIR}${PREFIX}/share/icons/hicolor
.include <bsd.port.mk>
