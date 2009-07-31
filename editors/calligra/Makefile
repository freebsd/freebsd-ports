# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.6.3
PORTREVISION=	9
PORTEPOCH=	2
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-${PORTVERSION:S/a//}/src
DIST_SUBDIR=	KDE/koffice

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Office Suite for KDE3

BUILD_DEPENDS=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx
LIB_DEPENDS=	GraphicsMagick++.1:${PORTSDIR}/graphics/GraphicsMagick \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl \
		aspell.16:${PORTSDIR}/textproc/aspell \
		exif.12:${PORTSDIR}/graphics/libexif \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		lcms.1:${PORTSDIR}/graphics/lcms \
		paper.2:${PORTSDIR}/print/libpaper \
		poppler-qt.2:${PORTSDIR}/graphics/poppler-qt \
		wpd-0.8.8:${PORTSDIR}/textproc/libwpd \
		wv2.2:${PORTSDIR}/textproc/wv2
RUN_DEPENDS=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_MYSQL=	yes
USE_PYTHON=	yes
USE_RUBY=	yes
USE_PGSQL=	yes
USE_GNOME=	libxml2 libxslt
MAKE_JOBS_UNSAFE=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

CONFIGURE_ARGS+=--with-pgsqlincdir=${LOCALBASE}/include \
		--with-pgsqllibdir=${LOCALBASE}/lib \
		--with-pqxx-includes=${LOCALBASE}/include \
		--with-pqxx-libraries=${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's|%%PYTHON_VER%%|${PYTHON_VER}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
