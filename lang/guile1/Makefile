PORTNAME=	guile
PORTVERSION=	1.8.8
CATEGORIES=	lang scheme
MASTER_SITES=	GNU
PKGNAMESUFFIX=	1

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GNU Ubiquitous Intelligent Language for Extension

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libgmp.so:math/gmp

USES=		autoreconf cpe gmake libtool makeinfo ncurses pathfix
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	guile2 guile

GNU_CONFIGURE=	yes
CFLAGS+=	-fwrapv
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
PORTSCOUT=	limit:^1\.

PLIST_SUB=	GUILE_VER=${PORTVERSION:R}

REINPLACE_FILES=	libguile/smob.c libguile/filesys.c libguile/gc.c \
			libguile/mallocs.c libguile/eval.c libguile/gc-malloc.c \
			libguile/ports.c libguile/gc-mark.c libguile/gc_os_dep.c

INFO=		goops guile-tut guile r5rs

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools

post-extract:
	@${FIND} ${WRKSRC}/doc -name "*.info*" -delete

post-patch:
	@cd ${WRKSRC} ; \
	  ${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' ${REINPLACE_FILES}
	@${REINPLACE_CMD} -e 's|$$(libdir)|$$(libdir)data|g' ${WRKSRC}/Makefile.am
	@${TOUCH} ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
