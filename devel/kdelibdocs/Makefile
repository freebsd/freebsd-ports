# New ports collection makefile for:   kdelibdocs
# Date created:        8 Feb 2000
# Whom:                imura@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME?=	kdelibdocs
PORTVERSION?=	1.1
CATEGORIES=	devel kde
MASTER_SITES=	ftp://129.187.206.68/pub/unix/ide/KDevelop/documentation/ \
		ftp://gd.tuwien.ac.at/hci/KDevelop/documentation/ \
		ftp://fara.cs.uni-potsdam.de/pub/kdevelop/documentation/
DISTNAME=	kdelibdocs-1.1

MAINTAINER=	imura@FreeBSD.org

LIB_DEPENDS?=	kdecore.3:${PORTSDIR}/x11/kdelibs11

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-qtdoc-dir=${X11BASE}/share/doc/qt/html" \
		"--with-qt-includes=${X11BASE}/include/X11/qt"

PATCHDIR=	${.CURDIR}/patches

.include <bsd.port.mk>
