# New ports collection makefile for:	long-exposure-tools
# Date created:		2004-08-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	long-exposure-tools
PORTVERSION=	0.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.qqqq.ca/cgi-bin/wiki.cgi/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulate the effects of long exposures

LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm

USE_REINPLACE=	yes

PLIST_FILES=	bin/pamblend bin/pamalign
MAN1=		pamblend.1 pamalign.1

post-patch:
	@${REINPLACE_CMD} -e 's|cc|${CC}|; \
		s|CCOPTS=-O|CCOPTS=${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib|' \
			${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pamblend ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pamalign ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pamblend.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pamalign.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
