# New ports collection makefile for:	guile
# Date created:		2 November 1997
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	guile
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	guile

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	GNU\'s Ubiquitous Intelligent Language for Extension

LIB_DEPENDS=	ltdl.1:${PORTSDIR}/devel/libtool

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFILES=	configure guile-readline/configure
CONFIGURE_ARGS=	--with-threads
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB=	GUILE_VER=${PORTVERSION}

REINPLACE_FILES=	libguile/gc.c libguile/mallocs.c \
			libguile/ports.c libguile/smob.c

post-extract:
	cd ${WRKSRC}; ${CHMOD} u+w ${REINPLACE_FILES}

post-patch:
	cd ${WRKSRC} ; \
	  ${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' ${REINPLACE_FILES}

.include <bsd.port.mk>
