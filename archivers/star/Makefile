# ex:ts=8
# New ports collection makefile for:	star
# Date created:		Thu May  1 20:28:44 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=		star
PORTVERSION=		1.2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.fokus.gmd.de/pub/unix/star/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=	obrien@FreeBSD.org

USE_GMAKE=	yes
MAKE_ENV=	MAKEPROG=gmake CCOM=${CC}
MAN1=		star.1
MLINKS=		star.1 ustar.1

.if ${MACHINE_ARCH} != "i386" || ${CC} != "cc"
post-extract:
	@${LN} -sf i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${MACHINE_ARCH}-freebsd-${CC}.rul
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/star/OBJ/${MACHINE_ARCH}-freebsd-cc/star \
		${PREFIX}/bin
	cd ${PREFIX}/bin ; ${LN} -f star ustar
	${INSTALL_MAN} ${WRKSRC}/star/star.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
