# New ports collection makefile for:	kxmleditor
# Date created:		15 July 2001
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kxmleditor
PORTVERSION=	0.7.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kevlo@FreeBSD.org

GNU_CONFIGURE=	yes

USE_KDELIBS_VER=2

CONFIGURE_ENV+=	LIBQT="-lqt2" MOC="moc2" KDEDIR="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-qt-includes=${X11BASE}/include/qt2 \
			--with-qt-libraries=${X11BASE}/lib

.include <bsd.port.mk>
