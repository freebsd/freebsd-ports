PORTNAME=	sftpgo
PORTVERSION=	2.6.6
PORTREVISION=	3
CATEGORIES=	ftp www
MASTER_SITES=	https://github.com/drakkan/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}_v${PORTVERSION}_src_with_deps

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Fully featured and highly configurable SFTP, FTP/S, and WebDAV server
WWW=		https://github.com/drakkan/sftpgo

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules tar:xz
USE_RC_SUBR=	${PORTNAME}

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=		BASH FISH ZSH MANPAGES
OPTIONS_DEFAULT=	BASH FISH ZSH MANPAGES
OPTIONS_SUB=		yes

USERS=		sftpgo
GROUPS=		sftpgo

post-patch:
	${REINPLACE_CMD} -e 's|"templates"|"${DATADIR}/templates"|; \
		s|"static"|"${DATADIR}/static"|; \
		s|"sftpgo.db"|"/var/db/${PORTNAME}/${PORTNAME}.db"|' \
		${WRKSRC}/${PORTNAME}.json

post-build-BASH-on:
	${GO_WRKDIR_BIN}/${PORTNAME} gen completion bash > ${WRKDIR}/bash_completions

post-build-FISH-on:
	${GO_WRKDIR_BIN}/${PORTNAME} gen completion fish > ${WRKDIR}/fish_completions

post-build-ZSH-on:
	${GO_WRKDIR_BIN}/${PORTNAME} gen completion zsh > ${WRKDIR}/zsh_completions

post-build-MANPAGES-on:
	${MKDIR} ${WRKDIR}/manpages
	${GO_WRKDIR_BIN}/${PORTNAME} gen man --dir ${WRKDIR}/manpages

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} templates ${STAGEDIR}${DATADIR} && \
		${COPYTREE_SHARE} static ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.json ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.json.sample

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKDIR}/bash_completions ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKDIR}/fish_completions ${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKDIR}/zsh_completions ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-MANPAGES-on:
	${FIND} ${WRKDIR}/manpages -type f -execdir ${INSTALL_MAN} {} ${STAGEDIR}${PREFIX}/share/man/man1 \;

.include <bsd.port.mk>
