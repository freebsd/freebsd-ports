# New ports collection makefile for:	kdeutils2
# Date created:				3 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdeutils
PORTVERSION=	3.0
CATEGORIES?=	misc kde
MASTER_SITES=	http://www.csociety.org/~will/kde/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

#WRKSRC=		${WRKDIR}/kdeutils
USE_KDELIBS_VER=3
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
MAN1=		efax.1 efix.1 fax.1

.include <bsd.port.mk>
