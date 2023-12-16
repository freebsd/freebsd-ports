PORTNAME=	agg
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.2
PORTREVISION=	3
CATEGORIES=	graphics
PKGNAMEPREFIX=	asciinema-

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Asciinema gif generator
WWW=		https://github.com/asciinema/agg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	asciinema

PLIST_FILES=	bin/agg

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/agg

.include <bsd.port.mk>
