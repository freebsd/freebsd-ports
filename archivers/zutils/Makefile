# Created by: Albert Vernon <f3cun3c02@sneakemail.com>
# $FreeBSD$

PORTNAME=	zutils
PORTVERSION=	1.9
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/zutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Utilities for searching in bzip2, gzip, lzip, and xz archives

LICENSE=	GPLv2

USES=		tar:lz
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

INFO=		zutils

post-patch:
	# Remove compiler hardcoded flags and use environment
	@${REINPLACE_CMD} '23,26d' ${WRKSRC}/configure

post-install:
	@-${RM} ${STAGEDIR}${PREFIX}/info/dir

.include <bsd.port.mk>
