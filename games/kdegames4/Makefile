# New ports collection makefile for:	kdegames2
# Date created:				Sun 14 May 2000 02:47:57
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegames
PORTVERSION=	1.90
CATEGORIES=	games kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR=	unstable/distribution/tar/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdecore.4:${PORTSDIR}/x11/kdelibs2

BROKEN=		"Does not compile/run properly"

MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_QT2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib
CONFIGURE_ENV+=	MOC="${MOC}"
USE_GMAKE=	yes

.include <bsd.port.mk>
