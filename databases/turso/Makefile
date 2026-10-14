PORTNAME=	turso
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	wen@FreeBSD.org
COMMENT=	In-process SQL database written in Rust, compatible with SQLite
WWW=		https://github.com/tursodatabase/turso

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo python:build

USE_GITHUB=	yes
GH_ACCOUNT=	tursodatabase

MAKE_ENV+=	PYO3_PYTHON=${PYTHON_CMD}

PLIST_FILES=	bin/tursodb

PORTSCOUT=	limit:^0\.

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/tursodb \
		${STAGEDIR}${PREFIX}/bin/tursodb

.include <bsd.port.mk>
