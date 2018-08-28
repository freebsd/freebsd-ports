# $FreeBSD$

PORTNAME=	jimtcl
PORTVERSION=	0.78
CATEGORIES=	lang tcl

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Small footprint implementation of the Tcl programming language

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ssl

USE_GITHUB=	yes
GH_ACCOUNT=	msteveb

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--full \
		--enable-utf8 \
		--enable-shared

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		DOCS
DOCS_CONFIGURE_ENABLE=	docs
DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR}
PORTDOCS=		*

TEST_TARGET=		test

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jimsh

.include <bsd.port.mk>
