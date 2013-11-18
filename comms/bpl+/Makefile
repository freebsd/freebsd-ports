# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bpl+
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	max
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	B Plus file transfer protocol

PLIST_FILES=	bin/bp bin/bpl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpl ${STAGEDIR}${PREFIX}/bin
	(cd ${STAGEDIR}${PREFIX}/bin; ${LN} -sf bpl bp)

.include <bsd.port.mk>
