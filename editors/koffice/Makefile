# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdecore.4:${PORTSDIR}/x11/kdelibs2 \
		iconv.2:${PORTSDIR}/converters/iconv

USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV+= LIBQT="-lqt2" MOC="${MOC}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lgcc -lstdc++"
USE_GMAKE=	yes

.include <bsd.port.mk>
