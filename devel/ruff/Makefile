PORTNAME=	ruff
DISTVERSION=	0.5.5
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extremely fast Python linter, written in Rust
WWW=		https://github.com/charliermarsh/ruff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: evaluation of constant value failed, see https://github.com/briansmith/ring/issues/2006

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	astral-sh

#CARGO_BUILD_ARGS=	--package=file://${WRKSRC}/crates/ruff_cli
CARGO_INSTALL_PATH=	crates/ruff_cli

PROGS=		ruff \
		ruff_dev \
		ruff_python_formatter

PLIST_FILES=	${PROGS:S/^/bin\//} \
		share/bash-completion/completions/ruff \
		share/elvish/lib/ruff.elv \
		share/fish/vendor_completions.d/ruff.fish \
		share/zsh/site-functions/_ruff

PORTSCOUT=	limit:^.*0\.0\.2[56789].* # don't report before 0.0.25x+

do-install:
	# workaround for error: found a virtual manifest at `xx` instead of a package manifest
.for p in ${PROGS}
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/*/release/${p} \
		${STAGEDIR}${PREFIX}/bin
.endfor
	# generate shell completions
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${WRKDIR}/target/*/release/${PORTNAME} generate-shell-completion bash > ${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/elvish/lib
	${WRKDIR}/target/*/release/${PORTNAME} generate-shell-completion elvish > ${STAGEDIR}${PREFIX}/share/elvish/lib/${PORTNAME}.elv
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${WRKDIR}/target/*/release/${PORTNAME} generate-shell-completion fish > ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/${PORTNAME}.fish
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${WRKDIR}/target/*/release/${PORTNAME} generate-shell-completion zsh > ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
