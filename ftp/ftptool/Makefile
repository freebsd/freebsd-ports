# New ports collection makefile for:	Ftptool
# Date created:		19 March 1996
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	ftptool
PORTVERSION=	4.6
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
DISTFILES=	Ftptool${PORTVERSION}.tar.gz

MAINTAINER=	janek@gaja.ipan.lublin.pl

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/Ftptool4.6

# Because lex.l is broken, lex.c is taken from old FreeBSD 1.1 port

post-extract:
	@${CP} ${FILESDIR}/lex.c ${WRKSRC}
	@${RM} -f ${WRKSRC}/lex.l

.include <bsd.port.mk>
