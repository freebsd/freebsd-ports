# New ports collection makefile for:	gucharmap
# Date created:				02 Mar 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gucharmap
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Unicode/ISO10646 character map and font viewer

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
WANT_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LDFLAGS="-L${LOCALBASE}/lib"

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
.undef WITHOUT_GNOME
.undef WITHOUT_ALL
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
PKGNAMESUFFIX=	-gnome
.else
CONFIGURE_ARGS=	--disable-gnome
.endif

.include <bsd.port.post.mk>
