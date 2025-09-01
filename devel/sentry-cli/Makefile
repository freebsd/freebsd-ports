PORTNAME=	sentry-cli
DISTVERSION=	2.31.0
PORTREVISION=	15
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Command line utility to work with Sentry
WWW=		https://docs.sentry.io/cli/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgit2.so:devel/libgit2 \
		libzstd.so:archivers/zstd

USES=		cargo ssl:build
USE_GITHUB=	yes
GH_ACCOUNT=	getsentry

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS REPORTING
OPTIONS_DEFAULT=	REPORTING

REPORTING_DESC=	Enable crash reporting
REPORTING_VARS=	CARGO_FEATURES+=with_crash_reporting

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
