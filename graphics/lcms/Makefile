# New ports collection makefile for:	lcms
# Date created:		October 30, 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	lcms
PORTVERSION=	1.09
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.littlecms.com/
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com

INSTALLS_SHLIB=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j2
WRKSRC=		${WRKDIR}/${DISTNAME}/src

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${PREFIX}/share/doc/lcms
	${CP} -rp ${WRKSRC}/../doc/* ${WRKSRC}/../tifficc/tifficc.c \
		${WRKSRC}/../jpegicc/jpegicc.c ${WRKSRC}/../jpegicc/iccjpeg.c \
		${WRKSRC}/../samples/wtpt.c ${WRKSRC}/../samples/icctrans.c \
		${PREFIX}/share/doc/lcms/
.endif

post-build test:
	cd ${WRKSRC}/../testbed && \
		${SETENV} CFLAGS="${CFLAGS} -I../include" ${MAKE} -E CFLAGS test

.include <bsd.port.mk>
