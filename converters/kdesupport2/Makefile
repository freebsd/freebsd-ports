# New ports collection makefile for:	kdesupport2
# Date created:				Sun May 14 2000 01:14:20
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdesupport
PORTVERSION=	2.1
CATEGORIES=	converters kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib \
		--without-audiofile
CONFIGURE_ENV+= LIBQT="-lqt2" MOC="${MOC}" \
		CPPFLAGS="-I${LOCALBASE}/include -D_GETOPT_H" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lstdc++ -lgcc"

pre-configure:
	${PERL} -pi -e "s@-version-info 1:1@-version-info 3:0@g" ${WRKSRC}/mimelib/Makefile.in

.include <bsd.port.mk>
