# New ports collection makefile for:	XShipWars-Game-Client
# Date created:				Nov 7th 1999
# Whom:					troll
#
# $FreeBSD$
#

PORTNAME=	xshipwars-client
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://fox.mit.edu/pub/xsw/
DISTFILES=	xsw1.23.tgz stimages1.3.tgz

MAINTAINER=	troll@digitalspark.net
COMMENT=	Hardcore Internet space combat/economy game resembling EV on crack!

WRKSRC=		${WRKDIR}/xsw1.23/client
USE_XLIB=	YES
USE_XPM=	yes
USE_GMAKE=	YES
MAKEFILE=	Makefile.FreeBSD

post-install:
	@ ${ECHO} "===>   Initalizing Sounds Directory"
	@ ${TOUCH} ${PREFIX}/share/xshipwars/sounds/SoundsGoHere
	@ ${ECHO} "===>   Installing Default Image Set "
	@ ${MKDIR} ${PREFIX}/share/xshipwars
	@ ${CP} -R ${WRKSRC}/../../images \
	   ${PREFIX}/share/xshipwars/
	@ ${CHMOD} -R 744 ${PREFIX}/share/xshipwars
	@ ${CHMOD} -R a+X ${PREFIX}/share/xshipwars
	@ ${ECHO} "===>   Installing Documentation "
	@ ${MKDIR} ${PREFIX}/share/doc/xshipwars
	@${INSTALL_DATA} ${WRKSRC}/../README \
	   ${PREFIX}/share/doc/xshipwars
	@${INSTALL_DATA} ${WRKSRC}/../CREDITS \
	   ${PREFIX}/share/doc/xshipwars
	@${INSTALL_DATA} ${WRKSRC}/../DOCS_NOW_ONLINE \
	   ${PREFIX}/share/doc/xshipwars
	@${INSTALL_DATA} ${WRKSRC}/../INSTALL \
	   ${PREFIX}/share/doc/xshipwars
	@${INSTALL_DATA} ${WRKSRC}/../LICENSE \
	   ${PREFIX}/share/doc/xshipwars
	@${INSTALL_DATA} ${WRKSRC}/../TODO \
	   ${PREFIX}/share/doc/xshipwars
	@ ${ECHO} "===>   Stripping Binary "
	@ ${STRIP_CMD} ${PREFIX}/bin/xsw

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
