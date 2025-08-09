PORTNAME=	xtxf
DISTVERSION=	0.11.4
CATEGORIES=	games

MAINTAINER=	slowdive@me.com
COMMENT=	Terminal-based screensaver
WWW=		https://github.com/charlesrocket/xtxf

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig>=0.14:lang/zig

USE_GITHUB=	yes
GH_ACCOUNT=	charlesrocket
GH_TUPLE=	termbox:termbox2:9c9281a:zig_termbox/../.cache/zig/p/N-V-__8AAOfjBAD89_CGaCDSoVLTnCjzs3NRNGCkfL9zNuNo \
		00JCIV00:cova:4c56696:zig_cova/../.cache/zig/p/cova-0.10.1-AAAAAPqeBAAThnQ-eGLXG9tyPsBRehaw8ySs8nEPwMUy \
		charlesrocket:ghext:0.7.2:zig_ghext/../.cache/zig/p/ghext-0.7.2-dKaQN31QAABGONiBUrG8LuTUWwpEbiXF4syy_NmTdizp

BUILD_ARGS=	--prefix ${PREFIX} ${WITH_DEBUG:U-Doptimize=ReleaseFast} \
		${WITH_PIE:D-Dpie} -Dcpu=${CPUTYPE:Ubaseline} --verbose

MAKE_ENV=	DESTDIR=${STAGEDIR}

PLIST_FILES=	bin/xtxf \
		share/man/man6/xtxf.6.gz

OPTIONS_DEFAULT=		BASH ZSH
OPTIONS_GROUP=			COMPLETION
OPTIONS_GROUP_COMPLETION=	BASH ZSH
BASH_DESC=			Install BASH completion
ZSH_DESC=			Install ZSH completion

BASH_PLIST_FILES=	share/bash-completion/completions/xtxf-completion.bash
ZSH_PLIST_FILES=	share/zsh/site-functions/_xtxf-completion.zsh

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build ${BUILD_ARGS}

post-build:
	@cd ${WRKSRC} && ${STAGEDIR}${PREFIX}/bin/cova_generator_xtxf
	@${RM} ${STAGEDIR}${PREFIX}/bin/cova_generator_xtxf

do-install:
	${INSTALL_MAN} ${WRKSRC}/meta/help_docs/manpages/xtxf.6 \
		${STAGEDIR}${PREFIX}/share/man/man6

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xtxf

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/meta/tab_completions/xtxf-completion.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/xtxf-completion.bash

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/meta/tab_completions/_xtxf-completion.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_xtxf-completion.zsh

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} zig build test ${BUILD_ARGS}

.include <bsd.port.mk>
