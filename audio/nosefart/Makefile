PORTNAME=	nosefart
PORTVERSION=	1.92f
PORTREVISION=	1
CATEGORIES=	audio emulators
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}-${PORTVERSION}-mls

MAINTAINER=	sethk@meowfishies.com
COMMENT=	Player for NES Sound Format (NSF)
WWW=		https://nosefart.sourceforge.net/

LICENSE=	GPLv2

USES=		cpe gmake
MAKE_ENV=	INSTALL="${INSTALL}" COPY="${COPY}" STRIP="${STRIP}" \
		BINGRP="${BINGRP}" BINMODE="${BINMODE}" BINOWN="${BINOWN}"
CPE_VENDOR=	nosefart_project

EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/nsfobj \
			--exclude *.bat \
			--exclude *.exe \
			--no-same-owner --no-same-permissions

PLIST_FILES=	bin/nosefart

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsfobj/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
