# New ports collection makefile for:	star-devel
# Date created:				19.06.2004 22:27:00 CEST
# Whom:					Martin Matuska <martin@matuska.org>
#
# $FreeBSD$
#

PORTNAME=	star
PORTVERSION=	1.5.a.58
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/alpha/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./a/}

MAINTAINER=	martin@matuska.org
COMMENT=	Unique standard tape archiver with many enhancements

BUILD_DEPENDS=	${LOCALBASE}/bin/smake:${PORTSDIR}/devel/smake

CONFLICTS=	star-1.4*
LATEST_LINK=	star-devel

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.a.*//g}

USE_BZIP2=	yes
MAN1=		star.1
MLINKS=		star.1 ustar.1
MAKE_ENV=	MAKEFLAGS=${MAKEFLAGS}

do-build:
	@cd ${WRKSRC} && ${MAKE_ENV} ${LOCALBASE}/bin/smake

do-install:
	@cd ${WRKSRC}/star && ${MAKE_ENV} ${LOCALBASE}/bin/smake install SYMLINKS="star ustar" INS_BASE=${PREFIX}

.include <bsd.port.mk>
