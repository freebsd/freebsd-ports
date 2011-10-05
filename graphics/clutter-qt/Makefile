# New ports collection makefile for:	clutter-qt
# Date created:		04 Aug 2009
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clutter-qt
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	QT+ Integration library for Clutter

LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

BROKEN=		Doesn't build with Glib-2.26

DEPRECATED=     upstream distfile and doesn't build, and doesn't seem to be developed anymore
EXPIRATION_DATE=2011-11-06

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${RM} ${WRKSRC}/examples/moc_testqt.cc \
		${WRKSRC}/clutter-qt/moc_clutter-qt.cc

.include <bsd.port.mk>
