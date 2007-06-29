# ex:ts=8
# Ports collection makefile for:	classpath
# Date created:			Sep 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	classpath
PORTVERSION=	0.92
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNU project to create a free Java class library

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_LDCONFIG=	yes
USE_JAVA=	yes
USE_JIKES=	yes
USE_GNOME=	gtk20 gdkpixbuf pkgconfig gconf2
GNU_CONFIGURE=	yes
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} `${PKG_CONFIG} gtk+-2.0 --cflags`" \
		LDFLAGS="`${PKG_CONFIG} gtk+-2.0 --libs`"
CONFIGURE_ARGS=	--enable-jni --with-jikes --disable-gtk-peer --disable-plugin
USE_GMAKE=	yes

INFO=		hacking tools vmintegration

.include <bsd.port.mk>
