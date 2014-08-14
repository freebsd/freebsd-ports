# Created by: Alan Somers <asomers@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyua-testers
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/kyua/releases/download/${PORTNAME}-${PORTVERSION}/ \
		LOCAL/jmmv

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Kyua (automated testing framework) - Testers

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_DEFAULT=TEST

OPTIONS_SUB=		yes
TEST_CONFIGURE_WITH=	atf
TEST_BUILD_DEPENDS=	atf>=0.20:${PORTSDIR}/devel/atf
TEST_RUN_DEPENDS=	atf>=0.20:${PORTSDIR}/devel/atf
TEST_USES=		pkgconfig

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}

MAKE_FLAGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif

.include <bsd.port.mk>
