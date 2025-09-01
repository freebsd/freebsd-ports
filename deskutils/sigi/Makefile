PORTNAME=	sigi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.1
PORTREVISION=	11

CATEGORIES=	deskutils

MAINTAINER=	hiljusti@so.dang.cool
COMMENT=	Organizing tool for terminal lovers who hate organizing
WWW=		https://github.com/sigi-cli/sigi

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sigi-cli

CARGO_BUILD_ARGS=	--all

PLIST_FILES=	bin/sigi \
		share/man/man1/sigi.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
