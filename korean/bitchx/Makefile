# New ports collection makefile for:	BitchX ircII client patched for korean
# Date created:		3 Jun 1999
# Whom:			hollywar
#
# $FreeBSD$
#

PORTNAME=	bitchx
PORTVERSION=	75.1
CATEGORIES=	korean net
MASTER_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	bitchx-ko

MAINTAINER=	hollywar@mail.holywar.net

GNU_CONFIGURE=	yes

post-patch:
	${SED} -e s,__PREFIX__,$(PREFIX), $(WRKSRC)/include/config.h > $(WRKSRC)/include/config.h.new
	${MV} $(WRKSRC)/include/config.h.new $(WRKSRC)/include/config.h

do-install:
	${MKDIR} ${PREFIX}/lib/bx
	${INSTALL_PROGRAM} ${WRKSRC}/source/BitchX ${PREFIX}/bin
	@(${LN} -sf ${PREFIX}/bin/BitchX ${PREFIX}/bin/bx)
	${INSTALL_PROGRAM} ${WRKSRC}/source/scr-bx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/wserv ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/BitchX.help ${PREFIX}/lib/bx

.include <bsd.port.mk>
