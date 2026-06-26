PORTNAME=	sentry-cli
DISTVERSION=	3.5.0
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Command line utility to work with Sentry
WWW=		https://docs.sentry.io/cli/ \
		https://github.com/getsentry/sentry-cli

LICENSE=	FSL-1.1-MIT
LICENSE_NAME=	Functional Source License, Version 1.1, MIT Future License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgit2.so:devel/libgit2 \
		libzstd.so:archivers/zstd

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	getsentry

CARGO_ENV=	LIBGIT2_NO_VENDOR=1 \
		OPENSSL_NO_VENDOR=1

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
