# Created by: jseger@FreeBSD.org
# $FreeBSD$
#    $MCom: ports/lang/guile/Makefile,v 1.1 2006/09/12 14:57:06 ahze Exp $

PORTNAME=	guile
PORTVERSION=	1.8.8
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	guile

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Ubiquitous Intelligent Language for Extension

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

USE_AUTOTOOLS=	autoconf libltdl
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_NCURSES=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

GUILE_VER=	1.8
PLIST_SUB=	GUILE_VER=${GUILE_VER}

MAN1=		guile.1

REINPLACE_FILES=	libguile/smob.c libguile/filesys.c libguile/gc.c \
			libguile/mallocs.c libguile/eval.c libguile/gc-malloc.c \
			libguile/ports.c libguile/gc-mark.c libguile/gc_os_dep.c

INFO=		goops guile-tut guile r5rs

post-extract:
	cd ${WRKSRC}; ${CHMOD} u+w ${REINPLACE_FILES}
	@${FIND} ${WRKSRC}/doc -name "*.info*" -delete

post-patch:
	@cd ${WRKSRC} ; \
	  ${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' ${REINPLACE_FILES}
	@${REINPLACE_CMD} -e 's|2.63|%%AUTOCONF_VERSION%%|g' ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
