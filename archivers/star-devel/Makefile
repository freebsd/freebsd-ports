# New ports collection makefile for:	star-devel
# Date created:				19.06.2004 22:27:00 CEST
# Whom:					Martin Matuska <martin@tradex.sk>
#
# $FreeBSD$
#

PORTNAME=	star
PORTVERSION=	1.5.a.46
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/alpha/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./a/}

MAINTAINER=	martin@tradex.sk
COMMENT=	Unique standard tape archiver with many enhancements

CONFLICTS=	star-1.4*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.a.*//g}

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	MAKEPROG=${GMAKE} CCOM=${CC} LANG=C
MAN1=		star.1
MLINKS=		star.1 ustar.1

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

.include <bsd.port.mk>
