# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	gnubg
PORTVERSION=	0.15
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://www.gnubg.org/media/sources/:src \
		${MASTER_SITE_GNU_ALPHA:S/$/:ts/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:ts
DISTFILES=	gnubg-source-MAIN-20070601.tar.gz:src \
		gnubg_ts0.bd.gz:ts
EXTRACT_ONLY=	gnubg-source-MAIN-20070601.tar.gz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	GNU Backgammon

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		gdbm.4:${PORTSDIR}/databases/gdbm \
		png15:${PORTSDIR}/graphics/png \
		gtkextra-x11-2.0.1:${PORTSDIR}/x11-toolkits/gtkextra2 \
		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

WRKSRC=	${WRKDIR}/gnubg

OPTIONS_DEFINE=	ESOUND NLS
OPTIONS_DEFAULT=ESOUND NLS

CONFIGURE_ARGS=	--with-board3d

CONFIGURE_ENV=	ac_cv_path_ARTSC_CONFIG=no ac_cv_path_LIBART_CONFIG=no

USE_GNOME=	gnomehack libxml2
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	libtool automake
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
.else
CONFIGURE_ENV+=	ac_cv_path_AUDIOFILE_CONFIG=no ac_cv_path_ESD_CONFIG=no
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=	--enable-nls
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--disable-sse
.endif

MAN6=	gnubg.6
INFO=	gnubg

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_ts0.bd.gz > ${WRKSRC}/gnubg_ts0.bd

post-patch:
	${REINPLACE_CMD} -e 's|libpng12|libpng15|g' ${WRKSRC}/configure.in

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
