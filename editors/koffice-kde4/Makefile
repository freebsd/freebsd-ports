# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD>org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.90
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	unstable/distribution/tar/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdecore.4:${PORTSDIR}/x11/kdelibs2

BROKEN=		"Does not compile/run properly"

MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_QT2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib
CONFIGURE_ENV+=	MOC="${MOC}"
USE_GMAKE=	yes

.include <bsd.port.mk>
