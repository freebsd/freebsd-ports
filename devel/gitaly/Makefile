PORTNAME=	gitaly
DISTVERSION=	15.10.6
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab
WWW=		https://gitlab.com/gitlab-org/gitaly

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# Make sure the following patch is included:
# https://gitlab.com/gitlab-org/gitaly/-/merge_requests/4108
# it fixes segfaults reported here: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=259848

# define dependencies that are required for build and run under MY_DEPENDS
MY_DEPENDS=	git>=2.39.2:devel/git \
		rubygem-bundler>=2.1.4:sysutils/rubygem-bundler \
		rubygem-rugged>=1.5.1<1.6:devel/rubygem-rugged \
		rubygem-gitlab-markup>=1.9.0<1.10.0:textproc/rubygem-gitlab-markup \
		rubygem-activesupport61>=6.1.7.2<6.1.8:devel/rubygem-activesupport61 \
		rubygem-grpc>=1.42.0<2:net/rubygem-grpc \
		rubygem-sentry-raven>=3.1<4:devel/rubygem-sentry-raven \
		rubygem-rbtrace>=0.4.14:devel/rubygem-rbtrace \
		rubygem-gitaly>=15.5.0<15.10:net/rubygem-gitaly \
		rubygem-gitlab-labkit>=0.31<1:devel/rubygem-gitlab-labkit \
		rubygem-licensee>=9.15<10:devel/rubygem-licensee \
		rubygem-google-protobuf>=3.22.2<3.23:devel/rubygem-google-protobuf \
		rubygem-nokogiri>=1.14.1<1.15:textproc/rubygem-nokogiri \
		rubygem-license_finder>=7.0<8:devel/rubygem-license_finder \
		rubygem-redis4>=4.8.0<5:databases/rubygem-redis4
BUILD_DEPENDS=	gem:devel/ruby-gems \
		bash>0:shells/bash \
		${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS} \
		gitlab-shell>=14.17.0:devel/gitlab-shell
LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cpe gmake go:modules,no_targets pkgconfig ruby

CPE_VENDOR=	gitlab

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
# make sure to pass go build options into make process
MAKE_ENV+=	${GO_ENV}

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find this here: https://gitlab.com/gitlab-org/gitaly/-/tags
GL_COMMIT=	cd86fed226530143a2ccc39b6d5911fa3f67e2ab

# for go dependencies
# Gitlab hosts there dependencies on their own platform and not on go-proxy
# so we download the required go.mod file from gitlab
# lines are taken from go.mk
# ---------------------------
FETCH_DEPENDS=	${GO_CMD}:${GO_PORT} \
		ca_root_nss>0:security/ca_root_nss
MASTER_SITES+=	https://gitlab.com/gitlab-org/gitaly/-/raw/v${DISTVERSION}/
DISTFILES+=	go.mod
DIST_SUBDIR=	go/${PKGORIGIN:S,/,_,g}/${DISTNAME}
EXTRACT_ONLY+=	${DISTFILES:N*.mod\:*:N*.mod:C/:.*//}
_USES_fetch+=	800:go-post-fetch
go-post-fetch:
	@${ECHO_MSG} "===> Fetching ${GO_MODNAME} dependencies";
	@(cd ${DISTDIR}/${DIST_SUBDIR}; \
		[ -e go.mod ] || ${RLN} ${GO_MODFILE} go.mod; \
		${SETENV} ${GO_ENV} GOPROXY=${GO_GOPROXY} ${GO_CMD} mod download -x all)
# ---------------------------

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/config.toml.example
	${MV} ${WRKSRC}/config.toml.example ${WRKSRC}/config.toml.sample

pre-build:
	(cd ${WRKSRC}/ruby && ${RM} Gemfile.lock && bundle install --local)

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${FIND} ${WRKSRC} -name "Gemfile.lock" -delete
	(cd ${WRKSRC}/_build/bin/ && ${COPYTREE_SHARE} .  ${STAGEDIR}${DATADIR}/bin && \
	cd ${WRKSRC} && ${COPYTREE_SHARE} config.toml.sample  ${STAGEDIR}${DATADIR}) && \
	cd ${WRKSRC}/ruby && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ruby

post-install:
	${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		/gitlab-shell-hook$$/ s#^#@(,,755) #; \
		s#${DATADIR_REL}/ruby/bin#@(,,555) ${DATADIR_REL}/ruby/bin#; \
		s#${DATADIR_REL}/bin#@(,,555) ${DATADIR_REL}/bin#; ' >> ${TMPPLIST}

.include <bsd.port.mk>
