# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.5.0
PORTEPOCH=	2
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-${PORTVERSION:S/a//}/src
DIST_SUBDIR=	KDE/koffice

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Office Suite for KDE3

BUILD_DEPENDS=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx \
		Magick-config:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		aspell:${PORTSDIR}/textproc/aspell \
		exif.12:${PORTSDIR}/graphics/libexif \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		lcms:${PORTSDIR}/graphics/lcms \
		paper:${PORTSDIR}/print/libpaper \
		wpd-0.8:${PORTSDIR}/textproc/libwpd \
		wv2:${PORTSDIR}/textproc/wv2 \
		xml2:${PORTSDIR}/textproc/libxml2 \
		xslt:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx

USE_AUTOTOOLS=  libtool:15
INSTALLS_SHLIB=	yes
PREFIX=		${KDE_PREFIX}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_MYSQL=	yes
USE_PYTHON=	yes
USE_RUBY=	yes
USE_PGSQL=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--with-pgsqlincdir=${LOCALBASE}/include \
		--with-pgsqllibdir=${LOCALBASE}/lib

.if ${OSVERSION} < 500035
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-kexi-main-keximainwindowimpl.cpp
CONFIGURE_ARGS+= --disable-final
.endif

post-configure:
.if ${OSVERSION} < 500035
	${REINPLACE_CMD} -e 's|\(^CPPFLAGS =.*\)|\1 -I${LOCALBASE}/include/stlport|g' \
	-e 's|\(^LDFLAGS =.*\)|\1 -L${LOCALBASE}/lib -lstlport_gcc ${PTHREAD_LIBS}|g' \
		${WRKSRC}/filters/krita/tiff/Makefile \
		${WRKSRC}/filters/kspread/excel/sidewinder/Makefile \
		${WRKSRC}/kchart/Makefile \
		${WRKSRC}/kchart/kdchart/Makefile \
		${WRKSRC}/kexi/kexidb/drivers/pqxx/Makefile \
		${WRKSRC}/kexi/migration/pqxx/Makefile
.endif

.include <bsd.port.post.mk>
