# New ports collection makefile for:	kdesupport2
# Date created:				Sun May 14 2000 01:14:20
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdesupport
PORTVERSION=	20000829A
CATEGORIES=	converters kde
MASTER_SITES=	http://www.physics.purdue.edu/~will/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	qt2.4:${PORTSDIR}/x11-toolkits/qt22

MOC=		${X11BASE}/bin/moc2
SOMAJOR=	8
SOMINOR=	0
USE_BZIP2=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--without-libjpeg --without-libgif \
		--without-libgdbm --without-libuulib \
		--without-odbc --without-audiofile \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV+= LIBQT="-lqt2" MOC="${MOC}" LIBQTFILE="libqt2" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -L${X11BASE}/lib -lqt2 -ljpeg -lstdc++ -lgcc"
USE_GMAKE=	yes
PLIST_SUB+=	LIBVER="${SOMAJOR}"

pre-configure:
	${PERL} -pi -e "s@TOPSUBDIRS libaps@TOPSUBDIRS@g" ${WRKSRC}/configure
	${PERL} -pi -e "s@odbc libaps@odbc@g" ${WRKSRC}/configure

pre-install:
	@(find ${WRKSRC} -name CVS | xargs rm -rf)

.include <bsd.port.mk>
