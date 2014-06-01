# Created by: Josh Elsasser <jre@vineyard.net>
# $FreeBSD$

PORTNAME=	lua-mode.el
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	lang elisp
MASTER_SITES=	http://lua-users.org/files/wiki_insecure/editors/
DISTNAME=	lua-mode.el
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs/XEmacs major mode for editing Lua scripts

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

PLIST_FILES=	share/emacs/site-lisp/lua-mode.el lib/xemacs/site-lisp/lua-mode.el
PLIST_DIRSTRY=	lib/xemacs/site-lisp lib/xemacs

do-install:
	@${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
	@${MKDIR} ${STAGEDIR}${XEMACSLISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} \
		${STAGEDIR}${EMACSLISPDIR}/lua-mode.el
	${LN} -sf ${EMACSLISPDIR}/lua-mode.el ${STAGEDIR}${XEMACSLISPDIR}

.include <bsd.port.mk>
