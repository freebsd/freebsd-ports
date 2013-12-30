# Created by: Bruce M Simpson
# $FreeBSD$

PORTNAME=	ifd-test
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	devel security
MASTER_SITES=	http://www.linuxnet.com/drivers/readers/files/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	IFD Test Suite for PC/SC Lite

LIB_DEPENDS=    pcsclite.1:${PORTSDIR}/devel/pcsc-lite

USE_GMAKE=	yes

NOMAN=
PLIST_FILES=	sbin/ifdtest
MAKE_ENV=	LIBS="-L${PREFIX}/lib -lpcsclite"

post-patch:
	${REINPLACE_CMD} -e "s,LPSTR,LPTSTR,g; s,LPCSTR,LPCTSTR,g; \
		s,[P]*SCARD_READERSTATE_A,SCARD_READERSTATE\*,g" \
		${WRKSRC}/commands.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifdtest ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
