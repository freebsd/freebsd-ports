# New ports collection makefile for:	guile
# Date created:		2 November 1997
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	guile
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	guile

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFILES=	configure guile-readline/configure
CONFIGURE_ARGS=	--with-threads
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB=	GUILE_VER=${PORTVERSION}

post-patch:
	@(cd ${WRKSRC} ; \
	  ${FIND} . -type f -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		"s|<malloc.h>|<stdlib.h>|g")

.include <bsd.port.mk>
