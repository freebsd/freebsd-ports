# New ports collection makefile for:	fargoal
# Date Created:				13 December 2003
# Whom:				 	chris_pressey@yahoo.ca
#
# $FreeBSD$
#

PORTNAME=	fargoal
PORTVERSION=	20040629
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/squidfighter/${PORTNAME}/20040630
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Remake of classic roguelike game "Sword of Fargoal"

LIB_DEPENDS=	alleg.42:${PORTSDIR}/devel/allegro

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_ZIP=	yes
USE_GMAKE=	yes

SUB_FILES=	${PORTNAME}-sh

do-install:
# Script
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${PREFIX}/bin/${PORTNAME}

# Program
	@${INSTALL_PROGRAM} ${WRKSRC}/../sword ${PREFIX}/libexec/${PORTNAME}

# Data
.for f in agreement.txt data gfx sfx
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/../${f} ${DATADIR}
.endfor

post-install:
# Fix permissions
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.mk>
