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
MOC=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

# Hack to make pthread support work correctly.  Even if we have a
# libqt2-mt, it may not be wise to build with it if we don't have
# a threads stub for X.
.if exists(${X11BASE}/lib/libqt2-mt.so)
.if exists(${X11BASE}/lib/libXThrStub.so)
QTNAME=		"qt2-mt"
.if ${OSVERSION} >= 500016
PTHREAD_CFLAGS=	""
PTHREAD_LIBS=	"-lc_r"
.else
PTHREAD_CFLAGS=	"-D_THREAD_SAFE"
PTHREAD_LIBS=	"-pthread"
.endif
.else
QTNAME=		"qt2"
PTHREAD_CFLAGS=	""
PTHREAD_LIBS=	""
.endif
.endif

CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib \
		--without-audiofile
CONFIGURE_ENV+= LIBQT="-l${QTNAME}" MOC="${MOC}" LIBQTFILE="lib${QTNAME}" \
		CPPFLAGS="-I${LOCALBASE}/include -D_GETOPT_H ${PTHREAD_CFLAGS}" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lstdc++ -lgcc ${PTHREAD_LIBS}"
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e "s@TOPSUBDIRS libaps@TOPSUBDIRS@g ; \
		s@odbc libaps@odbc@g" ${WRKSRC}/configure
	${PERL} -pi -e "s@-version-info 1:1@-version-info 3:0@g" ${WRKSRC}/mimelib/Makefile.in

.include <bsd.port.post.mk>
