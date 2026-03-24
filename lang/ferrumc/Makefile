PORTNAME=	ferrumc
DISTVERSION=	0.3.0
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ferrum-language compiler with compile-time memory safety
WWW=		https://ferrum-language.github.io/Ferrum/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz

DISTFILES=	ferrumc-v${DISTVERSION}-freebsd-x86_64.tar.gz

MASTER_SITES=	https://github.com/Ferrum-Language/Ferrum/releases/download/v${DISTVERSION}/
DIST_SUBDIR=	ferrumc

NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/ferrumc ${STAGEDIR}${PREFIX}/bin/ferrumc

.include <bsd.port.mk>
