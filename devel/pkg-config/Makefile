# New ports collection makefile for:	pkgconfig
# Date created:				30 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkgconfig
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

DISTFILES=	pkgconfig-0.5.0.tar.gz glib-1.2.10.tar.gz

USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure glib-1.2.8/configure
LIBTOOLFLAGS=	--disable-ltlibs \
		--disable-shared

PLIST_SUB=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

MAN1=		pkg-config.1

post-extract:
	@${RM} -rf ${WRKSRC}/glib-1.2.8
	@${CP} -R ${WRKSRC}/../glib-1.2* ${WRKSRC}/glib-1.2.8

post-install:
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_MAN} ${WRKSRC}/pkg-config.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
