# New ports collection makefile for:	Ftptool
# Version required:	4.6
# Date created:		19 March 1996
# Whom:			janek@gaja.ipan.lublin.pl
#
# $Id: Makefile,v 1.3 1996/12/01 01:22:47 obrien Exp $
#

DISTNAME=	ftptool-4.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
DISTFILES=	Ftptool4.6.tar.gz

MAINTAINER=	janek@gaja.ipan.lublin.pl

LIB_DEPENDS=	xview\\.3\\.:${PORTSDIR}/x11-toolkits/xview-lib

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/Ftptool4.6

# Because lex.l is broken, lex.c is taken from old FreeBSD 1.1 port

post-extract:
	@${CP} ${FILESDIR}/lex.c ${WRKSRC}
	@${RM} -f ${WRKSRC}/lex.l

.include <bsd.port.mk>
