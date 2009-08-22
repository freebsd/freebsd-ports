# New ports collection makefile for:    libstocks
# Date created:         this 7th day of January, 2002
# Whom:                 Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	libstocks
PORTVERSION=	0.5.0
CATEGORIES=	finance devel
MASTER_SITES=	SF

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A C library which can be used to fetch stocks quotes

USE_LDCONFIG=	yes
REINPLACE_ARGS=	-i ""

post-patch:
	${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
			-e 's/__UNIX__/__unix__/' \
		$$(${GREP} --mmap -El '<malloc.h>|__UNIX__' \
			${WRKSRC}/lib/*.c); \


do-build do-install:
.for d in lib client
	cd ${WRKSRC}/$d && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} -j2 \
		-f ${FILESDIR}/Makefile.$d ${.TARGET:S/do-//}
.endfor

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
