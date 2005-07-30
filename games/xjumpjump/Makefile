# New ports collection makefile for:	xjumpjump
# Date created:				9 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xjumpjump
PORTVERSION=	0.12
CATEGORIES=	games
# mastersite disappeared in January 2002
MASTER_SITES=	# http://makosteszta.sote.hu/linux/jumpjump/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Logical game for X Window System

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

USE_X_PREFIX=	yes

pre-build:
	@ ${RM} ${WRKSRC}/xjumpjump

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xjumpjump ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xjumpjump
	@ ${INSTALL_DATA} ${WRKSRC}/READ.ME ${PREFIX}/share/xjumpjump
	@ ${INSTALL_DATA} ${WRKSRC}/OLVASS.EL ${PREFIX}/share/xjumpjump

.include <bsd.port.mk>
