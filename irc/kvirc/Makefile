# New ports collection makefile for:   kvirc
# Date created:        05 January 2004
# Whom:                Michael Ranner
#
# $FreeBSD$
#

PORTNAME=	kvirc
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	irc kde
MASTER_SITES=	ftp://ftp.kvirc.net/pub/%SUBDIR%/ \
				ftp://ftp.de.kvirc.net/%SUBDIR%/ \
				ftp://ftp.kvirc.de/pub/%SUBDIR%/ \
				ftp://kvirc.firenze.linux.it/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}-beta2/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta2

MAINTAINER=		mranner@inode.at
COMMENT=	"IRC client for QT and KDE"

USE_KDELIBS_VER=3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--with-freebsd-pthread

MAN1=	kvirc.1

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
