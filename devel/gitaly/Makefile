PORTNAME=	gitaly
DISTVERSIONPREFIX=	v
DISTVERSION=	${GITLAB_VERSION}
PORTREVISION=	${GITLAB_PORTREVISION} # modify it in www/gitlab/Makefile.common
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab
WWW=		https://gitlab.com/gitlab-org/gitaly

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash>0:shells/bash \
		${LOCALBASE}/bin/cmake:devel/cmake-core \
		pcre2>0:devel/pcre2 \
		http-parser>0:www/http-parser
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libiconv.so:converters/libiconv \
		libpcre2-8.so:devel/pcre2

USES=		cpe gmake go:modules,no_targets,1.23 iconv pkgconfig

CPE_VENDOR=	gitlab

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
GL_TUPLE=	gitlab-org:git:v${GITLAB_GIT_VERSION}:_build/_build/deps/git-v${GITLAB_GIT_VERSION_SHORT}
GO_MOD_DIST=	gitlab
GO_MODULE=	gitlab.com/gitlab-org/gitaly/v18

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
# make sure to pass go build options into make process
MAKE_ENV+=	${GO_ENV}
# parallel build failed in my tests, so disable it here
MAKE_JOBS_UNSAFE=yes

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/config.toml.example
	${MV} ${WRKSRC}/config.toml.example ${WRKSRC}/config.toml.sample

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${FIND} ${WRKSRC} -name '*.orig' -delete
	(cd ${WRKSRC}/_build/bin/ && ${COPYTREE_BIN} .  ${STAGEDIR}${DATADIR}/bin && \
	cd ${WRKSRC} && ${COPYTREE_SHARE} config.toml.sample  ${STAGEDIR}${DATADIR})

post-install:
	${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		/gitlab-shell-hook$$/ s#^#@(,,755) #; \
		s#${DATADIR_REL}/bin#@(,,555) ${DATADIR_REL}/bin#; ' >> ${TMPPLIST}

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
