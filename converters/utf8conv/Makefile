# ex:ts=8
# New ports collection makefile for:	utf8conv
# Date created:			Jul 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	utf8conv
PORTVERSION=	1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.fibrespeed.net/~mbabcock/code/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert hexadecimal Unicode character values to UTF-8

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/utf8conv ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
