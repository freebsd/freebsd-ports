# New ports collection makefile for:	star
# Version required:	1,0
# Date created:		Thu May  1 20:28:44 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.6 1997/10/09 21:04:45 andreas Exp $
#

DISTNAME=		star-1.2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.fokus.gmd.de/pub/unix/star/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=	andreas@FreeBSD.ORG

USE_GMAKE=	yes
MAKE_ENV=	MAKEPROG=gmake
MAN1=		star.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/star/OBJ/i386-freebsd-cc/star ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/star ${PREFIX}/bin/ustar
	${INSTALL_MAN} ${WRKSRC}/star/star.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
