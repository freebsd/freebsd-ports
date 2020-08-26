# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=		orafce
DISTVERSIONPREFIX=	VERSION_
DISTVERSION=		3_13_4
CATEGORIES=		databases
PKGNAMEPREFIX=		postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Oracle's compatibility functions and packages for PostgreSQL

LICENSE=	0BSD
LICENSE_NAME=	Zero-Clause BSD / Free Public License 1.0.0
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.orafce
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake pgsql:9.5+
USE_GITHUB=	yes
LLD_UNSAFE=	yes

WANT_PGSQL=	server

PORTDOCS=	COPYRIGHT.orafce NEWS README.asciidoc

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's/DOCS = README/#&/' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/orafce.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(for f in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${STAGEDIR}${DOCSDIR}; done)

.include <bsd.port.mk>
