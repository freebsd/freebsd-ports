PORTNAME=	gitlab_query_language
PORTVERSION=	0.20.11
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Library  to compile GitLab Query Language (GLQL) queries to GraphQL
WWW=		https://gitlab.com/gitlab-org/glql/-/tree/main/glql_rb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rb_sys>=0.9.91<0.10:lang/rubygem-rb_sys

USES=		cargo gem gmake llvm:build

# Required to be able to build the rust library the gem uses
GEMFILES:=	${DISTNAME}.gem
DISTFILES+=	${DISTNAME}.gem
GEMS_SKIP_SUBDIR=	1
CARGO_VENDOR_DIR=	${WRKSRC}/ext/gitlab_query_language/cargo-crates
CARGO_CARGOTOML=	${WRKSRC}/ext/gitlab_query_language/Cargo.toml
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_ENV+=	CARGO_NET_OFFLINE=true
GEM_ENV+=	MAKE=gmake \
		${CARGO_ENV}

# update the crates file with:
# make makesum
# make clean extract
# make cargo-crates > Makefile.crates
# make makesum

post-extract:
	# change the gitlab external cargo (glql) to use already vendored local path
	@${MKDIR} ${WRKSRC}/ext/gitlab_query_language/vendor
	@${CP} -a ${WRKDIR}/glql-* ${WRKSRC}/ext/gitlab_query_language/vendor/glql
	@${SED} -i '' \
		-e 's|glql = { git = .* }|glql = { path = "${WRKSRC}/ext/gitlab_query_language/vendor/glql" }|' \
		${WRKSRC}/ext/gitlab_query_language/Cargo.toml

.include <bsd.port.mk>
