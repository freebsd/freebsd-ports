# New ports collection makefile for:	bugsquish
# Date created:				2004 05 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugsquish
PORTVERSION=	0.0.6
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/bugsquish/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bug-squishing, fly-swatting action

USE_SDL=	mixer image
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.mk>
