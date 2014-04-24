# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wkhtmltopdf
PORTVERSION=	0.12.0
PORTREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	GH:wk \
		http://github.com/${GH_ACCOUNT}/qt/archive/${WKQT_TAGNAME}.tar.gz?dummy=/:wkqt
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:wk \
		wkhtmltopdf-qt-${PORTVERSION}.tar.gz:wkqt

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Convert HTML (or live webpages) to PDF or image files

LICENSE=	LGPL3
LICENSE_FILE_LGPL3=	${INSTALL_WRKSRC}/COPYING

LIB_DEPENDS+=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2

USE_GITHUB=		yes
GH_ACCOUNT=		wkhtmltopdf
GH_PROJECT=		wkhtmltopdf
GH_COMMIT=		03c001d
GH_TAGNAME=		0.12.0
WKQT_TAGNAME=		wkhtmltopdf_0.12.0

USES=			pkgconfig gmake perl5
USE_XORG=		x11 xext xrender
USE_PERL5=		build
USE_LDCONFIG=		yes
HAS_CONFIGURE=		yes

WRKSRC=		${WRKDIR}/qt-${WKQT_TAGNAME}
INSTALL_WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}

OPTIONS_DEFINE=	BUNDLED_LIBS
BUNDLED_LIBS_DESC=	Use Qt-bundled jpeg, mng, png and tiff

CONFIGURE_ARGS=	-prefix ${WRKDIR}/qt-wk \
	-release -static -fast -exceptions -no-accessibility -no-stl \
	-no-sql-ibase -no-sql-mysql -no-sql-odbc -no-sql-psql -no-sql-sqlite \
	-no-sql-sqlite2 -no-qt3support -xmlpatterns -no-phonon \
	-no-phonon-backend -webkit -no-scripttools -no-mmx -no-3dnow -no-sse \
	-no-sse2 -system-zlib \
	-graphicssystem raster -opensource -confirm-license \
	-nomake tools -nomake examples -nomake demos -nomake docs \
	-nomake translations -no-opengl -no-dbus -no-multimedia -openssl \
	-no-declarative -largefile -rpath -no-nis -no-cups -no-iconv -no-pch \
	-no-gtkstyle -no-nas-sound -no-sm -no-xshape -no-xinerama -no-xcursor \
	-no-xfixes -no-xrandr -no-mitshm -no-xinput -no-xkb -no-glib -no-openvg \
	-no-opengl -no-xsync -no-audio-backend -no-sse3 -no-ssse3 -no-sse4.1 \
	-no-sse4.2

MAKE_ARGS+=	INSTALL_ROOT="${STAGEDIR}${PREFIX}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		fails to extract on FreeBSD 7.X
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not link on powerpc
.endif

.if ${PORT_OPTIONS:MBUNDLED_LIBS}
CONFIGURE_ARGS+=	-qt-libtiff -qt-libpng -qt-libmng -qt-libjpeg
.else
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libmng.so:${PORTSDIR}/graphics/libmng \
		libtiff.so:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	-system-libtiff -system-libpng -system-libmng \
			-system-libjpeg
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|/usr/X11R6/include|${LOCALBASE}/include/X11|g' \
		-e 's|/usr/X11R6/lib|${LOCALBASE}/lib|g' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e "s|gcc|${CC}|g" -e "s|g++|${CXX}|g" \
		${WRKSRC}/mkspecs/common/g++-base.conf

post-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET} INSTALL_ROOT=
	@cd ${INSTALL_WRKSRC} && ${WRKDIR}/qt-wk/bin/qmake && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS:C,^${DESTDIRNAME}=.*,,g} \
		${ALL_TARGET}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/wkhtmltopdf \
		${STAGEDIR}${PREFIX}/bin/wkhtmltoimage
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
