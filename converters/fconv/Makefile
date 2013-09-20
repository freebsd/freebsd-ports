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

MAKE_ENV+=	INSTALLDIR=${PREFIX}/bin

NO_STAGE=	yes
post-extract:
	@${REINPLACE_CMD} "s|^INSTALLDIR.*=|INSTALLDIR?=|" \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
