# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aha
PORTVERSION=	0.5.1
CATEGORIES=	converters
PKGNAMESUFFIX=	-theZiz

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	ANSI escape-coded formatted output to HTML converter

LICENSE=	LGPL20+ MPL11
LICENSE_COMB=	dual

USE_GITHUB=	yes
USES=		gmake

GH_ACCOUNT=	theZiz
GH_PROJECT=	aha

PLIST_FILES=	bin/aha man/man1/aha.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aha
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/aha.1 \
		${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
