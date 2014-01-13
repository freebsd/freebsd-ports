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

NO_STAGE=	yes
.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
# TODO: install the tests, once FreeBSD has a system for ports to install tests
CONFIGURE_ARGS+=	--without-atf

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif
PLIST_SUBST+=	TESTS="@comment "

PORTDATA=	lib.subr tests_lib.subr
PORTDOCS=	AUTHORS COPYING NEWS README
MAN1=	atf-report.1 atf-run.1 atf2kyua.1

# Eliminate empty directories
remove-docsdir: .SILENT
	${RMDIR} ${DOCSDIR}

.if ! ${PORT_OPTIONS:MDOCS}
post-install: remove-docsdir
.endif

.include <bsd.port.mk>
