# ex:ts=8
# Ports collection makefile for:	kprof
# Date Created:			 	24 December 2001
# Whom:					Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	kprof
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pmarquis@pobox.com

USE_KDELIBS_VER=	2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	KDEDIR=${PREFIX} MOC=moc2 LIBQT=-lqt2
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-extra-includes=${PREFIX}/include \
		--with-extra-libs=${PREFIX}/lib \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib
USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

.include <bsd.port.mk>
