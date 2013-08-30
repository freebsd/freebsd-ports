# Created by: Seth Kingsley <sethk@osd.bsdi.com>
# $FreeBSD$

PORTNAME=	nosefart
PORTVERSION=	1.92f
PORTREVISION=	1
CATEGORIES=	audio emulators
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}-${PORTVERSION}-mls

MAINTAINER=	sethk@meowfishies.com
COMMENT=	Player for NES Sound Format (NSF)

LICENSE=	GPLv2

USES=		gmake
MAKE_ENV=	INSTALL="${INSTALL}" COPY="${COPY}" STRIP="${STRIP}" \
		BINGRP="${BINGRP}" BINMODE="${BINMODE}" BINOWN="${BINOWN}"

PLIST_FILES=	bin/nosefart

pre-build:
	@${RM} -rf ${BUILD_WRKSRC}/nsfobj

.include <bsd.port.mk>
