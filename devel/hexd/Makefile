PORTNAME=	hexd
DISTVERSIONPREFIX=v
DISTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	mail@dbalan.in
COMMENT=	Colourful, human-friendly hexdump tool
WWW=		https://github.com/FireyFly/hexd/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	FireyFly

PLIST_FILES=	bin/hexd \
		share/man/man1/hexd.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hexd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hexd.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
