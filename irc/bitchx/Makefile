# New ports collection makefile for:	BitchX ircII client
# Version required:	75p3
# Date created:		26 Jan 1998
# Whom:			griffin
#
# $Id: Makefile,v 1.3 1998/07/21 11:38:44 eivind Exp $
#

DISTNAME=	ircii-pana-75p3
PKGNAME=	bitchx-75p3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitchx.com/pub/BitchX/source/

MAINTAINER=	griffin@blackhole.iceworld.org

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/BitchX

post-patch:
	${SED} -e s,__PREFIX__,$(PREFIX), $(WRKSRC)/include/config.h > $(WRKSRC)/include/config.h.new
	${MV} $(WRKSRC)/include/config.h.new $(WRKSRC)/include/config.h

do-install:
	${MKDIR} ${PREFIX}/lib/bx
	${INSTALL_PROGRAM} ${WRKSRC}/source/BitchX ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/scr-bx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/wserv ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/BitchX.help ${PREFIX}/lib/bx

.include <bsd.port.mk>
