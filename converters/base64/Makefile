# New ports collection makefile for:	base64
# Date created:				29 Oct 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	base64
PORTVERSION=	0.1
CATEGORIES=	converters
MASTER_SITES=	http://www.codecenter.com/base64/
DISTNAME=	b64

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	clean all
MAN1=		base64.1

post-patch:
	@${PERL} -pi.in -e "s|b64|base64|g" ${WRKSRC}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/base64 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/base64.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
