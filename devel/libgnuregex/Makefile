PORTNAME=	libgnuregex
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	# Nothing to fetch
DISTFILES=	# Nothing to fetch

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	GNU Regex Library
WWW=		https://www.gnu.org/software/gnulib/

LICENSE=	LGPL20+

EXTRACT_DEPENDS=	gnulib>0:devel/gnulib

USES=		uidfix
USE_LDCONFIG=	yes

CFLAGS=		-I${WRKSRC}
MAKE_ENV+=	INCLUDEDIR="${PREFIX}/include" LIBDIR="${PREFIX}/lib"

REGEX_FILES=	lib/attribute.h \
		lib/cdefs.h \
		lib/dynarray.h \
		lib/gettext.h \
		lib/intprops.h \
		lib/intprops-internal.h \
		lib/libc-config.h \
		lib/regex.c \
		lib/regex.h \
		lib/regex_internal.c \
		lib/regex_internal.h \
		lib/regexec.c \
		lib/regcomp.c \
		lib/verify.h
REGEX_MALLOC_FILES=	lib/malloc/dynarray.h \
			lib/malloc/dynarray_resize.c \
			lib/malloc/dynarray-skeleton.c

do-extract:
	${MKDIR} -p ${WRKSRC}/malloc
	${CP} -a ${REGEX_FILES:C,^,${LOCALBASE}/share/gnulib/,} ${WRKSRC}
	${CP} -a ${REGEX_MALLOC_FILES:C,^,${LOCALBASE}/share/gnulib/,} ${WRKSRC}/malloc
	${CP} -a ${FILESDIR}/config.h ${FILESDIR}/gnuregex.h \
		${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/gnu

.include <bsd.port.mk>
