# New ports collection makefile for:    wzip
# Date created:		06 Jan 2003
# Whom:			Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	wzip
PORTVERSION=	1.1
CATEGORIES=	archivers
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/w/wzip/
DISTNAME=	wzip_${PORTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	A preprocessor for lossy data compression

ALL_TARGET=	wzip
WRKSRC=		${WRKDIR}/wzip-${PORTVERSION}
MAN1=		wzip.1
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} 's|gcc|${CC}|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wzip ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wzip.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
