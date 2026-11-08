PORTNAME=	janet-lsp
PORTVERSION=	0.0.13
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	dave@freedave.net
COMMENT=	LSP for lang/janet
WWW=		https://github.com/CFiggers/janet-lsp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	jpm>=1.2.0:lang/jpm
RUN_DEPENDS=	janet>=1.38.0:lang/janet

USE_GITHUB=	yes
GH_ACCOUNT=	CFiggers

# 0.0.13 now has a lockfile.jdn and we use that to match versions.
#
# Alphabetical order by project works but is coincidental and only because the
# sole depenedency is 'judge' on 'cmd'.
#
# This ordering is respected in do-build.
GH_TUPLE=	CFiggers:cmd:b0a34d6:cmd \
		CFiggers:jayson:4f54041:jayson \
		CFiggers:judge:1d329cb:judge \
		janet-lang:jpm:907daf1:jpm \
		janet-lang:spork:dbfc90d:spork

NO_ARCH=	yes
SUB_FILES=	janet-lsp

PLIST_FILES=	bin/janet-lsp \
		lib/janet/janet-lsp.jimage \
		lib/janet/.manifests/janet-lsp.jdn

# Use GH_TUPLE project-hash as directory to avoid an unnecessary copy.
do-build:
.for dep in ${GH_TUPLE:C@^([^:]*):([^:]*):([^:]*):([^:]*)@\2-\3@}
	cd ${WRKDIR}/${dep} && \
		${LOCALBASE}/bin/jpm --tree=${WRKSRC}/jpm_tree "install"
.endfor
	cd ${WRKSRC} && ${LOCALBASE}/bin/jpm --tree=${WRKSRC}/jpm_tree "install"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/janet/.manifests
	${INSTALL_SCRIPT} ${WRKDIR}/janet-lsp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/jpm_tree/lib/janet-lsp.jimage \
		${STAGEDIR}${PREFIX}/lib/janet
	${INSTALL_DATA} ${WRKSRC}/jpm_tree/lib/.manifests/janet-lsp.jdn \
		${STAGEDIR}${PREFIX}/lib/janet/.manifests

do-test:
	cd ${WRKSRC} && jpm test -l

.include <bsd.port.mk>
