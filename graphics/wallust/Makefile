PORTNAME=	wallust
DISTVERSION=	3.4.0
CATEGORIES=	graphics
MASTER_SITES=	https://codeberg.org/explosion-mental/${PORTNAME}/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Generate colors from an image
WWW=		https://explosion-mental.codeberg.page/wallust/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1PAGES=	${PORTNAME}-cs.1 \
		${PORTNAME}-run.1 \
		${PORTNAME}-theme.1 \
		${PORTNAME}.1
MAN5PAGES=	${PORTNAME}.5
PORTEXAMPLES=	${PORTNAME}.toml

OPTIONS_DEFINE=		COMPLETIONS EXAMPLES MANPAGES
OPTIONS_DEFAULT=	COMPLETIONS MANPAGES
OPTIONS_SUB=		yes

COMPLETIONS_DESC=	Build and/or install shell completions

post-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${EXAMPLESDIR}

post-install-MANPAGES-on:
.for man in ${MAN1PAGES}
	${INSTALL_MAN} ${WRKSRC}/man/${man} ${STAGEDIR}${PREFIX}/share/man/man1
.endfor
.for man in ${MAN5PAGES}
	${INSTALL_MAN} ${WRKSRC}/man/${man} ${STAGEDIR}${PREFIX}/share/man/man5
.endfor

.include <bsd.port.mk>
