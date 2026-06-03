PORTNAME=	taskwarrior-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27.0
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Terminal User Interface for Taskwarrior
WWW=		https://kdheepak.com/taskwarrior-tui/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	task:deskutils/taskwarrior

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	kdheepak
CARGO_TEST=	no

PLIST_FILES=	bin/taskwarrior-tui \
		share/bash-completion/completions/taskwarrior-tui \
		share/fish/vendor_completions.d/taskwarrior-tui.fish \
		share/man/man1/taskwarrior-tui.1.gz \
		share/zsh/site-functions/_taskwarrior-tui

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/taskwarrior-tui.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/taskwarrior-tui
	${INSTALL_DATA} ${WRKSRC}/completions/taskwarrior-tui.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/taskwarrior-tui.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_taskwarrior-tui \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_taskwarrior-tui
	${INSTALL_MAN} ${WRKSRC}/packaging/man/taskwarrior-tui.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
