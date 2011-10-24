# New ports collection makefile for:	ruby-mode.el
# Date created:		6 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby-mode.el
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION=	${RUBY_PORTREVISION}
PORTEPOCH=	1
CATEGORIES=	lang ruby elisp
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp modules for the Ruby language

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch

USE_RUBY=	yes
RUBY_VER=	1.8
RUBY_NO_BUILD_DEPENDS=	yes

WRKSRC=		${WRKDIR}/elisp
NO_BUILD=	yes

ELISP_FILES=	inf-ruby.el ruby-mode.el rubydb3x.el

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${PORTSDIR}/${RUBY_PORT}; ${MAKE} -V WRKSRC`/misc ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/* ${RUBY_ELISPDIR}/
	${MKDIR} ${XEMACSLISPDIR}
.for f in ${ELISP_FILES}
	${LN} -sf ${RUBY_ELISPDIR}/${f} ${EMACSLISPDIR}/
	${LN} -sf ${RUBY_ELISPDIR}/${f} ${XEMACSLISPDIR}/
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
