# Created by: sethk
# $FreeBSD$

PORTNAME=	chordpack
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://sweb.cz/dan.polansky/chordpack/

MAINTAINER=	sethk@meowfishies.com
COMMENT=	Script to convert ChordPro files to HTML, ASCII, and TeX

USES=		shebangfix perl5 tar:tgz
SHEBANG_FILES=	chordpack
USE_PERL5=	run
NO_WRKSUBDIR=	true
NO_BUILD=	true

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/chordpack ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/chordpro-mode.el  \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/chordpack-documentation.html	\
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
