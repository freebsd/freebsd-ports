# New ports collection makefile for:	xpad
# Date created:		6 March 2002
# Whom:			Guillaume Paquet <amyfoub@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	xpad
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amyfoub@videotron.ca
COMMENT=	A virtual note-pad system for your X11 desktop

#WRKSRC=		${WRKDIR}/${DISTNAME}

USE_BZIP2=	yes

#USE_X_PREFIX=	yes
USE_GNOME=	gtk20

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		xpad.1
MANCOMPRESSED=	no

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/src/xpad ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/xpad.1 ${PREFIX}/man/man1/
	@${MKDIR} ${PREFIX}/share/xpad
	${INSTALL_DATA} ${WRKSRC}/images/xpad.xpm ${PREFIX}/share/xpad/
	${INSTALL_DATA} ${WRKSRC}/images/xpad2.xpm ${PREFIX}/share/xpad/
	${INSTALL_DATA} ${WRKSRC}/images/sticky.xpm ${PREFIX}/share/xpad/

.include <bsd.port.mk>
