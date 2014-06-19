# Created by: Alan Somers <asomers@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyua-atf-compat
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	kyua

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Kyua (automated testing framework) - ATF compatibility tools

LICENSE=	BSD

RUN_DEPENDS+=	${LOCALBASE}/bin/kyua:${PORTSDIR}/devel/kyua-cli

GNU_CONFIGURE=	yes
USES=		pkgconfig

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_DEFAULT=TEST

OPTIONS_SUB=		yes
TEST_CONFIGURE_WITH=	atf
TEST_BUILD_DEPENDS=	atf>=0.20:${PORTSDIR}/devel/atf
TEST_RUN_DEPENDS=	atf>=0.20:${PORTSDIR}/devel/atf

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif

.include <bsd.port.mk>
