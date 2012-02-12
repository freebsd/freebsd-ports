# New ports collection makefile for:	tnef
# Date created:		21 March 2010
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wkhtmltopdf
DISTVERSION=	0.10.0_rc2
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}:wkhtmltopdf \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mm
DISTFILES=	${DISTNAME}.tar.bz2:wkhtmltopdf \
		wkhtml2pdf-wkhtmltopdf-qt-${WKQTVERSION}.tar.bz2

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Convert HTML (or live webpages) to PDF or image files
LIB_DEPENDS+=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/qt-${PORTNAME}-qt
INSTALL_WRKSRC=	${WRKDIR}/${PORTNAME}-${DISTVERSION}

WKQTVERSION=		1806ef3b
USE_XORG=		x11 xext xrender
USE_PERL5_BUILD=	yes
USE_LDCONFIG=		yes
USE_GMAKE=		yes
HAS_CONFIGURE=		yes
MAKE_JOBS_SAFE=		yes

OPTIONS=	BUNDLED_LIBS "Use Qt-bundled jpeg, mng, png and tiff" off

LICENSE=	GPLv3 LGPL3 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${INSTALL_WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${INSTALL_WRKSRC}/COPYING.LGPL
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE.LGPL

CONFIGURE_ARGS=	-prefix ${WRKDIR}/wkqt \
	-release -static -fast -exceptions -no-accessibility -no-stl \
	-no-sql-ibase -no-sql-mysql -no-sql-odbc -no-sql-psql -no-sql-sqlite \
	-no-sql-sqlite2 -no-qt3support -xmlpatterns -no-phonon \
	-no-phonon-backend -webkit -no-scripttools -no-mmx -no-3dnow -no-sse \
	-no-sse2 -system-zlib -qt-gif \
	-graphicssystem raster -opensource -confirm-license \
	-nomake tools -nomake examples -nomake demos -nomake docs \
	-nomake translations -no-opengl -no-dbus -no-multimedia -openssl \
	-no-declarative -largefile -rpath -no-nis -no-cups -no-iconv -no-pch \
	-no-gtkstyle -no-nas-sound -no-sm -no-xshape -no-xinerama -no-xcursor \
	-no-xfixes -no-xrandr -no-mitshm -no-xinput -no-xkb -no-glib -no-openvg \
	-no-opengl -no-xsync -no-audio-backend -no-sse3 -no-ssse3 -no-sse4.1 \
	-no-sse4.2

MAKE_ARGS+=	INSTALL_ROOT="${PREFIX}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		Does not build below FreeBSD 7.x
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not link on powerpc
.endif

.if defined(WITH_BUNDLED_LIBS)
CONFIGURE_ARGS+=	-qt-libtiff -qt-libpng -qt-libmng -qt-libjpeg
.else
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		mng:${PORTSDIR}/graphics/libmng \
		tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	-system-libtiff -system-libpng -system-libmng \
			-system-libjpeg
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|/usr/X11R6/include|${LOCALBASE}/include/X11|g' \
		-e 's|/usr/X11R6/lib|${LOCALBASE}/lib|g' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf

post-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} \
		INSTALL_ROOT=
	@cd ${WRKDIR}/${PORTNAME}-${DISTVERSION} && ${WRKDIR}/wkqt/bin/qmake && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/wkhtmltopdf ${PREFIX}/bin/wkhtmltoimage
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
