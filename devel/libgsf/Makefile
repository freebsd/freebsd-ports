# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgsf
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.8
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An extensible i/o abstraction for dealing with structured file formats

.if !exists(/usr/lib/libbz2.so.1)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack libbonobo gnomevfs2
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc/gsf \
		--disable-gtk-doc --with-gnome --with-bz2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
