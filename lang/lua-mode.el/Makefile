# Created by: Josh Elsasser <jre@vineyard.net>
# $FreeBSD$

PORTNAME=	lua-mode.el
PORTVERSION=	1.26
PORTREVISION=	2
CATEGORIES=	lang elisp
MASTER_SITES=	http://lua-users.org/files/wiki_insecure/editors/
DISTNAME=	lua-mode.el
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs/XEmacs major mode for editing Lua scripts

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

PLIST_FILES=	share/emacs/site-lisp/lua-mode.el \
		lib/xemacs/site-lisp/lua-mode.el

do-install:
	@${MKDIR} ${STAGEDIR}${EMACSLISPDIR} ${STAGEDIR}${XEMACSLISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} \
		${STAGEDIR}${EMACSLISPDIR}/lua-mode.el
	${SED} -i '' -e 's/last-command-char/last-command-event/g' ${STAGEDIR}${EMACSLISPDIR}/lua-mode.el
	${LN} -sf ${EMACSLISPDIR}/lua-mode.el ${STAGEDIR}${XEMACSLISPDIR}

.include <bsd.port.mk>
