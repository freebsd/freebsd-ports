# New ports collection makefile for:	kdestudio
# Date created:			Tuesday January 16, 2001
# Whom:				Trenton Schulz
#
# $FreeBSD$
#

PORTNAME=	kdestudio
PORTVERSION=	2.0.0
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.thekompany.com/pub/KDE_Studio/source/ \
		http://gauss.cord.edu/homepages/twschulz/demo/

MAINTAINER=	twschulz@cord.edu

LIB_DEPENDS=	kdeui.4:${PORTSDIR}/x11/kdelibs2

USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include" \
		MOC="${MOC}" LIBQT="-lqt2" LIBQTFILE="libqt2" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lgcc -lstdc++"

pre-configure:
	@/usr/bin/find ${WRKSRC} -name Makefile.in | /usr/bin/xargs ${PERL} -pi -e "s/CXXFLAGS = -O2 -Wall/#CXXFLAGS = do not touch me/"

.include <bsd.port.mk>
