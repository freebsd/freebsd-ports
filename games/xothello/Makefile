# New ports collection makefile for:	xothello
# Date created:				31 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xothello
PORTVERSION=	0.01
CATEGORIES=	games
# mastersite disappeared in January 2002
MASTER_SITES=	# http://makosteszta.sote.hu/linux/othello/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Othello aka Reversi game for X Window

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

NO_CDROM=	Possible trademark infringement

PLIST_FILES=	bin/xothello
USE_X_PREFIX=	yes

pre-build:
	@ ${RM} ${WRKSRC}/xothello

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xothello ${PREFIX}/bin

.include <bsd.port.mk>
