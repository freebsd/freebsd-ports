# ex:ts=8
# New ports collection makefile for:	sfront
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sfront
PORTVERSION=	0.86
CATEGORIES=	audio
MASTER_SITES=	http://www.cs.berkeley.edu/~lazzaro/sa/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A translator that converts MP4-SA files into efficient C programs

BROKEN=		"Size mismatch"
EXPIRATION_DATE=2004-08-20
DEPRECATED=	${BROKEN}

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_BISON=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/sfront

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sfront ${PREFIX}/bin

.include <bsd.port.mk>
