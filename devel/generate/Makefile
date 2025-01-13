PORTNAME=	generate
DISTVERSION=	3.0
CATEGORIES=	devel
MASTER_SITES=	http://www.druid.net/darcy/

MAINTAINER=	darcy@druid.net
COMMENT=	Simple text pre-processor
WWW=		https://www.druid.net/darcy/readme-generate.html

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		gmake tar:tgz

MAKE_ARGS=	BINDIR=${STAGEDIR}${PREFIX}/bin \
		MANDIR=${STAGEDIR}${PREFIX}/share/man

CONFLICTS_INSTALL=	julius php*-pear-Text_Highlighter

PLIST_FILES=	bin/generate bin/rgenerate share/man/man1/generate.1.gz

TEST_TARGET=	test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
