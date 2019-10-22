# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	open-usp-tukubai
PORTVERSION=	2014061402
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://uec.usp-lab.com/TUKUBAI/DOWNLOAD/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open usp Tukubai is OSS version of Tukubai commands set

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python:2.7,run shebangfix tar:bzip2
SHEBANG_FILES=	COMMANDS*/*
MAKE_ENV=	STAGEDIR=${STAGEDIR}
NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
