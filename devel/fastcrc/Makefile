# New ports collection makefile for:	fastcrc
# Date created:				27 April 1999
# Whom:					G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

PORTNAME=	fastcrc
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast CRC routines

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386

INSTALLS_SHLIB=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libfcrc.so.1 ${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/libfcrc.so.1 ${PREFIX}/lib/libfcrc.so
	${INSTALL_DATA} ${WRKSRC}/fastcrc.h ${PREFIX}/include
	${MKDIR} ${PREFIX}/share/doc/fastcrc
	${INSTALL_MAN} ${WRKSRC}/index.html ${PREFIX}/share/doc/fastcrc
	${INSTALL_PROGRAM} ${WRKSRC}/fc ${PREFIX}/bin

.include <bsd.port.mk>
