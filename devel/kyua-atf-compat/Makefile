# Created by: Alan Somers <asomers@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyua-atf-compat
PORTVERSION=	0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	kyua

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Kyua (automated testing framework) - ATF compatibility tools

LICENSE=	BSD

RUN_DEPENDS=	kyua:${PORTSDIR}/devel/kyua

GNU_CONFIGURE=	yes
USES=		pkgconfig

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
# TODO: install the tests, once FreeBSD has a system for ports to install tests
CONFIGURE_ARGS+=	--without-atf

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif

post-stage:
	# TODO(jmmv): Should not be necessary after updating this to 0.2.
	rmdir ${STAGEDIR}${PREFIX}/tests/kyua-atf-compat
	rmdir ${STAGEDIR}${PREFIX}/tests

.include <bsd.port.mk>
