# New ports collection makefile for:	guile
# Date created:		2 November 1997
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#    $MCom: ports/lang/guile/Makefile,v 1.1 2006/09/12 14:57:06 ahze Exp $

PORTNAME=	guile
PORTVERSION=	1.8.4
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	guile

MAINTAINER=	amatus@gnu.org
COMMENT=	GNU Ubiquitous Intelligent Language for Extension

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4

USE_AUTOTOOLS=	autoconf:261 libltdl:15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GUILE_VER=	1.8
PLIST_SUB=	GUILE_VER=${GUILE_VER}

REINPLACE_FILES=	libguile/gc.c libguile/mallocs.c \
			libguile/ports.c libguile/smob.c

INFO=		goops guile-tut guile r5rs

.include <bsd.port.pre.mk>

post-extract:
	cd ${WRKSRC}; ${CHMOD} u+w ${REINPLACE_FILES}
	@${FIND} ${WRKSRC}/doc -name "*.info*" -delete

post-patch:
	@cd ${WRKSRC} ; \
	  ${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' ${REINPLACE_FILES}
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/libguile/load.c
	@${REINPLACE_CMD} -e 's^sparc-\*-\*^sparc-*-*|sparc64-*-*^' ${WRKSRC}/configure

.include <bsd.port.post.mk>
