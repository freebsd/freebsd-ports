# $FreeBSD$

PORTNAME=	libgnuregex
PORTVERSION=	6.0
CATEGORIES=	devel
MASTER_SITES=	# Nothing to fetch
DISTFILES=	# Nothing to fetch

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	GNU Regex Library

LICENSE=	LGPL20+

EXTRACT_DEPENDS=	gnulib>0:devel/gnulib

USES=		uidfix
USE_LDCONFIG=	yes

MAKE_ENV+=	INCLUDEDIR="${PREFIX}/include" LIBDIR="${PREFIX}/lib"

REGEX_FILES=	lib/regex.c \
		lib/regex.h \
		lib/regex_internal.c \
		lib/regex_internal.h \
		lib/regexec.c \
		lib/regcomp.c

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} -a ${REGEX_FILES:C,^,${LOCALBASE}/share/gnulib/,} ${WRKSRC}
	${CP} -a ${FILESDIR}/config.h ${FILESDIR}/gnuregex.h \
		${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/gnu

.include <bsd.port.mk>
