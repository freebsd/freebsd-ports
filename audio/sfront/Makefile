# New ports collection makefile for:	sfront
# Date created:				Nov 4, 2001
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	sfront
PORTVERSION=	0.98
CATEGORIES=	audio
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A translator that converts MP4-SA files into efficient C programs

USE_BISON=	build
MAKE_JOBS_SAFE=	yes

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}/src

PLIST_FILES=	bin/sfront

post-patch:
	@${REINPLACE_CMD} -E '/^(OPT|CC|DBUG)/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
