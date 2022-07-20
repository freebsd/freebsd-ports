PORTNAME=	mp3val
PORTVERSION=	0.1.8
DISTVERSIONSUFFIX=	-src
CATEGORIES=	audio
MASTER_SITES=	SF/mp3val/mp3val/mp3val%20${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Program for MPEG audio stream validation

LICENSE=	GPLv2

USES=		gmake

ALL_TARGET=	mp3val
MAKEFILE=	Makefile.linux

PLIST_FILES=	bin/mp3val

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3val ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
