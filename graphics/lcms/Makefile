# New ports collection makefile for:	lcms
# Date created:		October 30, 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	lcms
PORTVERSION=	1.07
CATEGORIES=	graphics
MASTER_SITES=	http://www.littlecms.com/

MAINTAINER=	mi@aldan.algebra.com

INSTALLS_SHLIB=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j2
WRKSRC=		${WRKDIR}/${DISTNAME}/src

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${PREFIX}/share/doc/lcms
	${CP} -rp ${WRKSRC}/../doc/* ${WRKSRC}/../samples/tifficc.c \
		${WRKSRC}/../samples/wtpt.c ${WRKSRC}/../samples/neutral.c \
		${PREFIX}/share/doc/lcms/
.endif

post-build test:
	cd ${WRKSRC}/../testbed && \
		${SETENV} CFLAGS="${CFLAGS} -I../src" make -E CFLAGS test

.include <bsd.port.mk>
