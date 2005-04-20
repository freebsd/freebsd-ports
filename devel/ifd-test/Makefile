# New ports collection makefile for:	ifd-test
# Date created:		23 August 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	ifd-test
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel security
MASTER_SITES=	http://www.linuxnet.com/drivers/readers/files/

MAINTAINER=	bms@FreeBSD.org
COMMENT=	IFD Test Suite for PC/SC Lite

LIB_DEPENDS=    pcsclite.1:${PORTSDIR}/devel/pcsc-lite

USE_GMAKE=	yes
USE_REINPLACE=	yes

NOMAN=
PLIST_FILES=	sbin/ifdtest
MAKE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="-L${PREFIX}/lib -lpcsclite ${PTHREAD_LIBS}"

post-patch:
	${REINPLACE_CMD} -e "s,LPSTR,LPTSTR,g; s,LPCSTR,LPCTSTR,g" \
		${WRKSRC}/commands.h ${WRKSRC}/ifdtest.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifdtest ${PREFIX}/sbin

.include <bsd.port.mk>
