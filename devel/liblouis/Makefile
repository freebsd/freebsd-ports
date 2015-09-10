# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblouis
PORTVERSION=	2.6.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open-source Braille Translator And Back-translator

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

USES=		gmake libtool autoreconf
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblouis.so

.include <bsd.port.mk>
