PORTNAME=	janet-lsp
PORTVERSION=	0.0.11
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	dave@freedave.net
COMMENT=	LSP for lang/janet
WWW=		https://github.com/CFiggers/janet-lsp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# Technically jpm should depend on janet.
BUILD_DEPENDS=	janet>=1.17.2:lang/janet \
		jpm>=1.1.0:lang/jpm
RUN_DEPENDS=	janet>=1.17.2:lang/janet

USE_GITHUB=	yes
GH_ACCOUNT=	CFiggers

# These are a little more recent than latest releases. But there is no lockfile
# so by default jpm(1) would use HEAD. There is also a conflict for cmd and the
# CFiggers version is more recent (and required by janet-lsp).
# Alphabetical order by project works but is coincidental and only because the
# sole depenedency is 'judge' on 'cmd'.
#
# This ordering is respected in do-build.
GH_TUPLE=	CFiggers:cmd:b0a34d6:cmd \
		CFiggers:jayson:4f54041:jayson \
		ianthehenry:judge:3b92185:judge \
		janet-lang:spork:7b780cc:spork

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
	${INSTALL_SCRIPT} ${WRKDIR}/janet-lsp \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/jpm_tree/lib/janet-lsp.jimage \
		${STAGEDIR}${PREFIX}/lib/janet/janet-lsp.jimage
	${INSTALL_DATA} ${WRKSRC}/jpm_tree/lib/.manifests/janet-lsp.jdn \
		${STAGEDIR}${PREFIX}/lib/janet/.manifests/janet-lsp.jdn

do-test:
	cd ${WRKSRC} && jpm test -l

.include <bsd.port.mk>
