# New ports collection makefile for:    caitoo
# Date created:         11 June 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	caitoo
PORTVERSION=	0.6.6
CATEGORIES=	ftp kde
MASTER_SITES=	http://devel-home.kde.org/~caitoo/src/ \
		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	unstable/apps/network

MAINTAINER=	lioux@linf.unb.br

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11 \
		kfile.3:${PORTSDIR}/x11/kdelibs11 \
		kfm.3:${PORTSDIR}/x11/kdelibs11 \
		mediatool.3:${PORTSDIR}/x11/kdelibs11

USE_XLIB=	yes
USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
