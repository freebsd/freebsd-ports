# New ports collection makefile for:	guile
# Date created:		2 November 1997
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	guile
PORTVERSION=	1.6.4
PORTREVISION=	6
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	guile

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNU Ubiquitous Intelligent Language for Extension

USE_LIBLTDL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GUILE_VER=	1.6
PLIST_SUB=	GUILE_VER=${GUILE_VER}

REINPLACE_FILES=	libguile/gc.c libguile/mallocs.c \
			libguile/ports.c libguile/smob.c

INFO=		goops guile-tut guile r5rs

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-ia64
.endif

.if ${ARCH} != "ia64" && ${ARCH} != "amd64"
CONFIGURE_ARGS+=--with-threads
PLIST_SUB+=	THREADS:=""
.else
PLIST_SUB+=	THREADS:="@comment "
.endif

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
