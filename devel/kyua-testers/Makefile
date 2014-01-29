# Created by: Alan Somers <asomers@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyua-testers
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	kyua

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Kyua (automated testing framework) - Testers

LICENSE=	BSD

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
# TODO: install the tests, once FreeBSD has a system for ports to install tests
CONFIGURE_ARGS+=	--without-atf

MAKE_FLAGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif

.include <bsd.port.mk>
