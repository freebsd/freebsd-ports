# New ports collection makefile for:	khacc
# Date created:		22 Jan 2003
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	khacc
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qhacc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple KDE-base financial manager

LIB_DEPENDS=	qhacc.2:${PORTSDIR}/finance/qhacc
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-qhacc-includes=${X11BASE}/include \
		--with-qhacc-libs=${X11BASE}/lib \
		--with-qt-moc=${QT_PREFIX}/bin \
		--with-qt-libs=${QT_PREFIX}/lib

STRIP=		# none

post-patch:
	@${REINPLACE_CMD} -e 's|#! /bin/sh|#!${LOCALBASE}/bin/bash|g ; \
		 s|/usr/local/q|${X11BASE}/lib/q|g' ${WRKSRC}/khacc/khacc.orig

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/khacc-*

.include <bsd.port.mk>
