# New ports collection makefile for:	BitchX ircII client
# Version required:	75p3
# Date created:		26 Jan 1998
# Whom:			griffin
#
# $FreeBSD$
#

DISTNAME=	ircii-pana-75p3
PKGNAME=	bitchx-75p3
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.bitchx.org/pub/BitchX/source/ \
		ftp://ftp.buk.net/pub/software/bitchx/source/

MAINTAINER=	griffin@blackhole.iceworld.org

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/BitchX

MAN1=		BitchX.1
MANCOMPRESSED=	yes

post-patch:
	@${SED} -e s,__PREFIX__,$(PREFIX), $(WRKSRC)/include/config.h > $(WRKSRC)/include/config.h.new
	@${MV} $(WRKSRC)/include/config.h.new $(WRKSRC)/include/config.h

do-install:
	${MKDIR} ${PREFIX}/lib/bx
	${INSTALL_PROGRAM} ${WRKSRC}/source/BitchX ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/scr-bx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/wserv ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/BitchX.help ${PREFIX}/lib/bx
	${INSTALL_MAN} ${WRKSRC}/BitchX.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
