# New ports collection makefile for:	xmastermind
# Date created:				23 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		xmastermind
PORTVERSION=		0.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Mastermind game for X Window System

LIB_DEPENDS=		forms.1:${PORTSDIR}/x11-toolkits/xforms

USE_REINPLACE=		yes
USE_X_PREFIX=		yes

pre-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/list.h

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xmastermind ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/doc/xmastermind
.for file in BUGS README.for.developers README.for.users
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xmastermind
.endfor

.include <bsd.port.mk>
