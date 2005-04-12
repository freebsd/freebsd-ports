# New ports collection makefile for:	xpad
# Date created:		6 March 2002
# Whom:			Guillaume Paquet <amyfoub@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xpad
PORTVERSION=	2.6
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amyfoub@gmail.com
COMMENT=	A virtual note-pad system for your X11 desktop

USE_BZIP2=	yes

USE_GNOME=	gtk20

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		xpad.1
MANCOMPRESSED=	no

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/src/xpad ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/xpad.1 ${PREFIX}/man/man1/

	${MKDIR} ${PREFIX}/share/icons/hicolor/48x48/apps ${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/images/hicolor/48x48/apps/xpad.png ${PREFIX}/share/icons/hicolor/48x48/apps/
	${INSTALL_DATA} ${WRKSRC}/images/hicolor/scalable/apps/xpad.svg ${PREFIX}/share/icons/hicolor/scalable/apps/

.include <bsd.port.mk>
