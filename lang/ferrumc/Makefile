PORTNAME=	ferrumc
DISTVERSION=	0.3.0
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ferrum-language compiler with compile-time memory safety
WWW=		https://ferrum-language.github.io/Ferrum/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz

DISTFILES=	ferrumc-v${DISTVERSION}-freebsd-x86_64.tar.gz

MASTER_SITES=	https://github.com/Ferrum-Language/Ferrum/releases/download/v${DISTVERSION}/
DIST_SUBDIR=	ferrumc

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	prebuilt binary only available for amd64

NO_BUILD=	yes
PLIST_FILES=	bin/ferrumc

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/ferrumc ${STAGEDIR}${PREFIX}/bin/ferrumc

.include <bsd.port.mk>
