# New ports collection makefile for:	gwenview
# Date created:		22 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	gwenview
PORTVERSION=	0.17.0
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gwenview
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stefan.jahn@nemesis-sektor.de
COMMENT=	An image viewer and browser for the KDE environment

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=	3

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	gwenview.1

post-install:
	${RM} ${PREFIX}/share/locale/xx/LC_MESSAGES/gwenview.mo
	-${RMDIR} ${PREFIX}/share/locale/xx/LC_MESSAGES
	-${RMDIR} ${PREFIX}/share/locale/xx

.include <bsd.port.mk>
