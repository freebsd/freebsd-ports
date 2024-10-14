PORTNAME=	ad
DISTVERSION=	0.1.3
CATEGORIES=	editors

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Adaptable text editor
WWW=		https://crates.io/crates/ad-editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	xclip:x11/xclip

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sminez

PLIST_FILES=	bin/ad \
		share/man/man1/ad.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/ad.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
