# New ports collection makefile for:	star
# Version required:	1,0
# Date created:		Thu May  1 20:28:44 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.8 1999/05/31 05:08:06 steve Exp $
#

DISTNAME=		star-1.2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.fokus.gmd.de/pub/unix/star/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=	andreas@FreeBSD.ORG

NO_PACKAGE=	ignores cflags
USE_GMAKE=	yes
MAKE_ENV=	MAKEPROG=gmake
MAN1=		star.1

.if ${MACHINE_ARCH} != "i386"
post-extract:
	@${LN} -sf i386-freebsd-cc.rul ${WRKSRC}/RULES/${MACHINE_ARCH}-freebsd-cc.rul
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/star/OBJ/${MACHINE_ARCH}-freebsd-cc/star ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/star ${PREFIX}/bin/ustar
	${INSTALL_MAN} ${WRKSRC}/star/star.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
