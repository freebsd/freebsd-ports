# New ports collection makefile for:	BitchX ircII client
# Version required:	74p4
# Date created:		26 Jan 1998
# Whom:			griffin
#
# $Id: Makefile,v 1.2 1998/04/19 05:35:31 mph Exp $
#

DISTNAME=	ircii-pana-75p1
PKGNAME=	bitchx-75p1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitchx.com/pub/BitchX/source/

MAINTAINER=	griffin@blackhole.iceworld.org

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/BitchX

post-patch:
	${SED} -e s,__PREFIX__,$(PREFIX), $(WRKSRC)/include/config.h > $(WRKSRC)/include/config.h.new
	${MV} $(WRKSRC)/include/config.h.new $(WRKSRC)/include/config.h

do-install:
	${MKDIR} ${PREFIX}/lib/BitchX
	${INSTALL_PROGRAM} ${WRKSRC}/source/BitchX ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/wserv ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/BitchX.help ${PREFIX}/lib/BitchX

.include <bsd.port.mk>
