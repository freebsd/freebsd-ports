PORTNAME=	gitaly
DISTVERSIONPREFIX=	v
DISTVERSION=	17.1.6
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab
WWW=		https://gitlab.com/gitlab-org/gitaly

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# define dependencies that are required for build and run under MY_DEPENDS
MY_DEPENDS=	git>=2.45.2:devel/git
BUILD_DEPENDS=	bash>0:shells/bash \
		${LOCALBASE}/bin/cmake:devel/cmake-core \
		pcre2>0:devel/pcre2 \
		http-parser>0:www/http-parser \
		${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		cpe gmake go:modules,no_targets,1.22 iconv pkgconfig ssl

CPE_VENDOR=	gitlab

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
GO_MOD_DIST=	gitlab
GO_MODULE=	gitlab.com/gitlab-org/gitaly/v16

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
# make sure to pass go build options into make process
MAKE_ENV+=	${GO_ENV}

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

.include <bsd.port.mk>
