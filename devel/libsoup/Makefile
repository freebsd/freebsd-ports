# New ports collection makefile for:	libsoup
# Date created:				12 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsoup
PORTVERSION=	1.99.26
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.99
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A SOAP (Simple Object Access Protocol) implementation in C

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_GNOME=	gnomehack glib20
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
