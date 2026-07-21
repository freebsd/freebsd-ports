PORTNAME=	rhg
PORTVERSION=	7.2.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.mercurial-scm.org/release/
DISTFILES=	mercurial-${PORTVERSION}.tar.gz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Experimental Rust version of Mercurial
WWW=		https://www.mercurial-scm.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		cargo cpe python:build

WRKSRC=		${WRKDIR}/mercurial-${PORTVERSION}/rust
CARGO_INSTALL=	no

BINARY_ALIAS=	python3=${PYTHON_VERSION}

PLIST_FILES=	bin/rhg

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/rhg \
		${STAGEDIR}${PREFIX}/bin

.include "${.CURDIR}/Makefile.cargo"
.include <bsd.port.mk>
