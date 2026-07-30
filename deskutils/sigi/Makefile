PORTNAME=	sigi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.0
CATEGORIES=	deskutils

MAINTAINER=	justin@so.dang.cool
COMMENT=	Organizing tool for terminal lovers who hate organizing
WWW=		https://github.com/so-dang-cool/sigi

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	so-dang-cool

CARGO_BUILD_ARGS=	--all

PLIST_FILES=	bin/sigi \
		share/man/man1/sigi.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
