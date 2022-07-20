PORTNAME=	gitlab-shell
PORTVERSION=	14.7.4
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab Shell handles git commands for GitLab

LICENSE=	MIT

USES=		gmake go:modules,no_targets

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-shell/tags
GL_COMMIT=	44c66836a9e00ad691871050af98e92142aa95ea

USERS=		git
GROUPS=		git

#INSTALL_TARGET=	install-strip
ALL_TARGET=	build

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
# make sure to pass go build options into make process
MAKE_ENV+=	${GO_ENV}

# for go dependencies
# Gitlab hosts there dependencies on their own platform and not on go-proxy
# so we download the required go.mod file from gitlab
# lines are taken from go.mk
# ---------------------------
FETCH_DEPENDS=	${GO_CMD}:${GO_PORT} \
		ca_root_nss>0:security/ca_root_nss
MASTER_SITES+=	https://gitlab.com/gitlab-org/gitlab-shell/-/raw/v${DISTVERSION}/
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

VARLOGDIR=	/var/log/gitlab-shell

PLIST_FILES+=	"@dir(git,,755) ${VARLOGDIR}"

post-patch:
	${MV} ${WRKSRC}/config.yml.example ${WRKSRC}/config.yml.sample
	${CP} ${WRKSRC}/config.yml.sample ${WRKSRC}/config.yml
	${REINPLACE_CMD} -e 's|VERSION_STRING :=.*|VERSION_STRING := v${PORTVERSION}|g' ${WRKSRC}/Makefile

pre-install:
	${RM} -rf ${WRKSRC}/config.yml

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${FIND} ${WRKSRC} -name '*.orig' -delete
	(cd ${WRKSRC}/bin/ && ${COPYTREE_BIN} .  ${STAGEDIR}${DATADIR}/bin)
.for x in CHANGELOG LICENSE README.md VERSION config.yml.sample
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DATADIR}/
.endfor
.for x in support
	@${MKDIR} ${STAGEDIR}${DATADIR}/${x}
	(cd ${WRKSRC}/${x} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${x})
.endfor
	@${MKDIR} ${STAGEDIR}${VARLOGDIR}

post-install:
	${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		s#${DATADIR_REL}/bin#@(,,555) ${DATADIR_REL}/bin#; ' >> ${TMPPLIST}

.include <bsd.port.mk>

