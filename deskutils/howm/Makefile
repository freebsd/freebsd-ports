# $FreeBSD$

PORTNAME=	howm
PORTVERSION=	1.4.2
CATEGORIES=	deskutils
MASTER_SITES=	http://howm.sourceforge.jp/a/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Write fragmentarily and read collectively

GNU_CONFIGURE=	yes
USE_EMACS=	yes
ELISP=		action-lock.el bcomp.el cheat-font-lock.el \
		howm-common.el howm-date.el howm-menu.el howm-misc.el \
		howm-mode.el howm-reminder.el \
		howm-version.el howm-view.el howm.el riffle.el

OPTIONS_DEFINE=	COMPILED_ELISP DOCS EXAMPLES
OPTIONS_DEFAULT=COMPILED_ELISP
COMPILED_ELISP_DESC=	Install pre-compiled ELISP files
OPTIONS_SUB=	yes

do-install:
	(cd ${WRKSRC}; ${INSTALL_DATA} *.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR})
	(cd ${WRKSRC}; ${INSTALL_DATA} *.elc ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR})
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/ja ${STAGEDIR}${EXAMPLESDIR}/en
	(cd ${WRKSRC}; ${INSTALL_DATA} ja/0* ${STAGEDIR}${EXAMPLESDIR}/ja)
	(cd ${WRKSRC}; ${INSTALL_DATA} en/0* ${STAGEDIR}${EXAMPLESDIR}/en)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.png ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
