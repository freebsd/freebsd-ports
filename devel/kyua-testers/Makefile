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

NO_STAGE=	yes
.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
# TODO: install the tests, once FreeBSD has a system for ports to install tests
CONFIGURE_ARGS+=	--without-atf

PLIST_FILES=	libdata/pkgconfig/kyua-testers.pc libexec/kyua-atf-tester
PLIST_FILES+=	libexec/kyua-plain-tester libexec/kyua-tap-tester
.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif

PORTDOCS=	AUTHORS COPYING NEWS README
MAN1=	kyua-atf-tester.1 kyua-plain-tester.1 kyua-tap-tester.1 kyua-tester.1
MAN5=	kyua-tester-list.5 kyua-tester-result.5
MAN7=	kyua-atf-interface.7 kyua-plain-interface.7 kyua-tap-interface.7

post-patch: .SILENT
	@${REINPLACE_CMD} -e 's|@pkgconfigdir@|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
