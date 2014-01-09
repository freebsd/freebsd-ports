# Created by: Chris Costello <chris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fconv
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	chris

MAINTAINER=	chris@FreeBSD.org
COMMENT=	Converts DOS or Mac-style files to Unix format, and vice-versa

USES=		uidfix

MAKE_ARGS+=	INSTALLDIR=${STAGEDIR}${PREFIX}/bin

post-patch:
	@${REINPLACE_CMD} 's/root/${UID}/g; s/wheel/${GID}/g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
