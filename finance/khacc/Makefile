# New ports collection makefile for:	khacc
# Date created:		22 Jan 2003
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=		khacc
PORTVERSION=		1.4.1
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qhacc

MAINTAINER=		ports@FreeBSD.org

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-qt-moc=${QT_PREFIX}/bin \
			--with-qt-libs=${QT_PREFIX}/lib

.include <bsd.port.mk>
