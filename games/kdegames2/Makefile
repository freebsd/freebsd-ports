# New ports collection makefile for:	kdegames2
# Date created:				Sun 14 May 2000 02:47:57
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegames
PORTVERSION=	20000724A
CATEGORIES=	games kde
MASTER_SITES=	$(MASTER_SITE_LOCAL)
MASTER_SITE_SUBDIR=	will

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	qt2.4:${PORTSDIR}/x11-toolkits/qt22 \
		kdecore.4:${PORTSDIR}/x11/kdelibs2

WRKSRC=		${WRKDIR}/kdegames
MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_NEWGCC=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=	MOC="${MOC}" LIBQT="-lqt2" LIBQTFILE="libqt2" \
		LIBS="-Wl,-export-dynamic -L${X11BASE}/lib -lqt2 -L${LOCALBASE}/lib -ljpeg -lgcc -lstdc++" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
USE_GMAKE=	yes

pre-install:
	@(find ${WRKSRC} -name CVS | xargs rm -rf)

.include <bsd.port.mk>
