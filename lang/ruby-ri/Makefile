# New ports collection makefile for:	ri
# Date created:			5 April 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ri
PORTVERSION=	0.8a
CATEGORIES=	lang ruby
MASTER_SITES=	ftp://www.pragmaticprogrammer.com/ruby/downloads/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

ELISP_FILES=	ri.el

DOCS=		COPYING ChangeLog README
EMACS_DOCS=	Changelog DESCRIPTION

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

post-patch:
	${RUBY} -i -pe 'gsub %r|/usr/local|, "${PREFIX}"' \
		${WRKSRC}/contrib/dblack/emacs/ri.el

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
	${INSTALL_DATA} ${WRKSRC}/contrib/dblack/emacs/Emacs.rb ${RUBY_SITELIBDIR}/${PORTNAME}/op/
	${MKDIR} ${XEMACSLISPDIR}
.for f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/contrib/dblack/emacs/${f} ${RUBY_ELISPDIR}/
	${LN} -sf ${RUBY_ELISPDIR}/${f} ${EMACSLISPDIR}/
	${LN} -sf ${RUBY_ELISPDIR}/${f} ${XEMACSLISPDIR}/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/emacs
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${EMACS_DOCS}
	${INSTALL_DATA} ${WRKSRC}/contrib/dblack/emacs/${f} ${RUBY_MODDOCDIR}/emacs/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
