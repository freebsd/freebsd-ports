# New ports collection makefile for:	Ftptool
# Version required:	4.6
# Date created:		19 March 1996
# Whom:			janek@gaja.ipan.lublin.pl
#
# $Id$
#

DISTNAME=	ftptool-4.6
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.x.org/contrib/utilities \
		ftp://crl.dec.com/pub/X11/contrib/utilities/ \
		ftp://ftp.icm.edu.pl/pub/X11/contrib/utilities/
DISTFILES=	Ftptool4.6.tar.gz

MAINTAINER=	janek@gaja.ipan.lublin.pl

LIB_DEPENDS=	xview\\.3\\.:${PORTSDIR}/x11/xview-lib

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/Ftptool4.6

# Because lex.l is broken, lex.c is taken from old FreeBSD 1.1 port

post-extract:
	cp ${FILESDIR}/lex.c ${WRKSRC}
	rm -f ${WRKSRC}/lex.l

.include <bsd.port.mk>
