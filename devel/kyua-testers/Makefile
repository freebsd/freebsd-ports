# Created by: Alan Somers <asomers@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyua-testers
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	kyua

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Kyua (automated testing framework) - Testers

LICENSE=	BSD

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS TEST

OPTIONS_SUB=		yes
TEST_CONFIGURE_WITH=	atf

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}

MAKE_FLAGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif

.include <bsd.port.mk>
