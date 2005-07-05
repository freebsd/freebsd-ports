# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.4.0a
PORTEPOCH=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-${PORTVERSION:S/.0//:S/a//}/src
DIST_SUBDIR=	KDE/koffice

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Office Suite for KDE3

BUILD_DEPENDS=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx \
		Magick-config:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		aspell:${PORTSDIR}/textproc/aspell \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		lcms:${PORTSDIR}/graphics/lcms \
		paper:${PORTSDIR}/print/libpaper \
		pq:${PORTSDIR}/databases/postgresql74-client \
		wpd-0.8:${PORTSDIR}/textproc/libwpd \
		wv2:${PORTSDIR}/textproc/wv2 \
		xml2:${PORTSDIR}/textproc/libxml2 \
		xslt:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
PREFIX=		${KDE_PREFIX}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_MYSQL=	yes
USE_PYTHON=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-kexi-main-keximainwindowimpl.cpp
CPPFLAGS+=	-I${LOCALBASE}/include/stlport
LDFLAGS+=	-L${LOCALBASE}/lib -lstlport_gcc ${PTHREAD_LIBS}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
.endif

post-patch:
	@env TZ=UTC ${TOUCH} -t 200506221316 ${WRKSRC}/subdirs ${WRKSRC}/Makefile.am \
			${WRKSRC}/configure.files ${WRKSRC}/configure.in \
			${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4

.include <bsd.port.post.mk>
