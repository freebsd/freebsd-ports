# ex:ts=8
# New ports collection makefile for:	star
# Date created:		Thu May  1 20:28:44 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	star
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Unique standard tape archiver with many enhancements

CONFLICTS=	star-1.5*

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	MAKEPROG=${GMAKE} CCOM=${CC}
MAN1=		star.1
MLINKS=		star.1 ustar.1

.include <bsd.port.pre.mk>

post-extract:
.if ${MACHINE_ARCH} != "i386" || ${CC} != "cc"
	@${LN} -sf i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${MACHINE_ARCH}-freebsd-${CC}.rul
.endif

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/star/OBJ/${MACHINE_ARCH}-freebsd-${CC}/star \
		${PREFIX}/bin
	@cd ${PREFIX}/bin ; ${LN} -f star ustar
	@${INSTALL_MAN} ${WRKSRC}/star/star.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
