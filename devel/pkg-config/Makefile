# New ports collection makefile for:	pkgconfig
# Date created:				30 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkgconfig
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/devel/glib12:patch

USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	glib-1.2.8/configure
LIBTOOLFLAGS=	--disable-ltlibs \
		--disable-shared

PLIST_SUB=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

MAN1=		pkg-config.1

post-extract:
	@${RM} -rf ${WRKSRC}/glib-1.2.8
	@${CP} -R ${WRKDIRPREFIX}${.CURDIR}/../../devel/glib12/work/glib-1.2* \
		${WRKSRC}/glib-1.2.8

post-install:
	${MKDIR} ${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
