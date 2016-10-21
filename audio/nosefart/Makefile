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
	@${RM} -r ${BUILD_WRKSRC}/nsfobj

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsfobj/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
