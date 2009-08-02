# New ports collection makefile for:	GNU Backgammon
# Date created:		8 Dec 2002
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	gnubg
PORTVERSION=	0.15
PORTREVISION=	4
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
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4 \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		gtkextra-x11-2.0.1:${PORTSDIR}/x11-toolkits/gtkextra2 \
		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

WRKSRC=	${WRKDIR}/gnubg

OPTIONS=	ESOUND	"Enable sound support" ON	\
		NLS	"Enable gettext support" ON

CONFIGURE_ARGS=	--with-board3d

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_path_ARTSC_CONFIG=no ac_cv_path_LIBART_CONFIG=no

USE_GNOME=	gnomehack gnometarget libxml2
USE_GMAKE=	yes
USE_PYTHON=	2.0+
USE_AUTOTOOLS=	libtool:22 automake:110
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ESOUND)
USE_GNOME+=	esound
.else
CONFIGURE_ENV+=	ac_cv_path_AUDIOFILE_CONFIG=no ac_cv_path_ESD_CONFIG=no
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=	--enable-nls
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--disable-sse
.endif

MAN6=	gnubg.6
INFO=	gnubg

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-extract:
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_ts0.bd.gz > ${WRKSRC}/gnubg_ts0.bd

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.post.mk>
