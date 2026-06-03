PORTNAME=	stdman
DISTVERSION=	2024.07.05
CATEGORIES=	devel docs

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Formatted C++20 stdlib man pages
WWW=		https://github.com/jeaye/stdman

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	jeaye

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/*.3 ${STAGEDIR}${PREFIX}/share/man/man3

.include <bsd.port.mk>
