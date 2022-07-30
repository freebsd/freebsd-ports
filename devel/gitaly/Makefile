PORTNAME=	gitaly
DISTVERSION=	15.1.4
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# Make sure the following patch is included:
# https://gitlab.com/gitlab-org/gitaly/-/merge_requests/4108
# it fixes segfaults reported here: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=259848

# define dependencies that are required for build and run under MY_DEPENDS
MY_DEPENDS=	git>=2.36.1:devel/git \
		rubygem-bundler>=2.1.4:sysutils/rubygem-bundler \
		rubygem-rugged>=1.2<2:devel/rubygem-rugged \
		rubygem-github-linguist>=7.12.1<8:textproc/rubygem-github-linguist \
		rubygem-gitlab-markup>=1.8.0<1.9.0:textproc/rubygem-gitlab-markup \
		rubygem-activesupport61>=6.1.4.7<6.1.7:devel/rubygem-activesupport61 \
		rubygem-rdoc>=6.3.2<7.0:devel/rubygem-rdoc \
		rubygem-gitlab-gollum-lib>=4.2.7.10.gitlab.2<4.2.8:www/rubygem-gitlab-gollum-lib \
		rubygem-gitlab-gollum-rugged_adapter>=0.4.4.4.gitlab.1<0.4.5.0:www/rubygem-gitlab-gollum-rugged_adapter \
		rubygem-grpc142>=1.42.0.pre1<2:net/rubygem-grpc142 \
		rubygem-sentry-raven>=3.0<4:devel/rubygem-sentry-raven \
		rubygem-faraday1>=1.0.1<2:www/rubygem-faraday1 \
		rubygem-rbtrace>=0.4.14:devel/rubygem-rbtrace \
		rubygem-gitlab-labkit>=0.22.0<0.24:devel/rubygem-gitlab-labkit \
		rubygem-licensee>=9.14.1<9.15:devel/rubygem-licensee \
		rubygem-google-protobuf319>=3.19.0<3.20:devel/rubygem-google-protobuf319 \
		rubygem-gitlab-license_finder>=6.14.2.1<7:devel/rubygem-gitlab-license_finder
BUILD_DEPENDS=	gem:devel/ruby-gems \
		bash>0:shells/bash \
		${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS} \
		gitlab-shell>=13.22.1:devel/gitlab-shell
LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cpe gmake go:modules,no_targets pkgconfig
USE_RUBY=	yes

CPE_VENDOR=	gitlab

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
# make sure to pass go build options into make process
MAKE_ENV+=	${GO_ENV}

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find this here: https://gitlab.com/gitlab-org/gitaly/-/tags
GL_COMMIT=	bde9c15df3104aad76ad7b919954718ac81c3b1f

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
