# New ports collection makefile for:	org-mode.el
# Date created:		2007-02-15
# Whom:			Kai Wang <kaiw27@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	org-mode.el
PORTVERSION=	7.8.11
PORTREVISION=	1
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://orgmode.org/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	org-${PORTVERSION}

MAINTAINER=	jhein@symmetricom.com
COMMENT=	An Emacs mode for notes and project planning

DOCSDIR=	${PREFIX}/share/doc/org-mode
USE_EMACS=	yes
USE_GMAKE=	yes

INFO=		org${PORTVERSION}

CONTRIBS=	\
	babel/langs/ob-fomus.el \
	babel/langs/ob-oz.el \
	babel/library-of-babel.org \
	doc/fr-orgcard.tex \
	lisp/htmlize.el \
	lisp/org-annotate-file.el \
	lisp/org-bookmark.el \
	lisp/org-checklist.el \
	lisp/org-choose.el \
	lisp/org-collector.el \
	lisp/org-contacts.el \
	lisp/org-contribdir.el \
	lisp/org-depend.el \
	lisp/org-drill.el \
	lisp/org-element.el \
	lisp/org-elisp-symbol.el \
	lisp/org-eval-light.el \
	lisp/org-eval.el \
	lisp/org-exp-bibtex.el \
	lisp/org-expiry.el \
	lisp/org-export-generic.el \
	lisp/org-export.el \
	lisp/org-git-link.el \
	lisp/org-interactive-query.el \
	lisp/org-invoice.el \
	lisp/org-jira.el \
	lisp/org-learn.el \
	lisp/org-mac-iCal.el \
	lisp/org-mac-link-grabber.el \
	lisp/org-mairix.el \
	lisp/org-man.el \
	lisp/org-mime.el \
	lisp/org-mtags.el \
	lisp/org-panel.el \
	lisp/org-registry.el \
	lisp/org-screen.el \
	lisp/org-secretary.el \
	lisp/org-static-mathjax.el \
	lisp/org-sudoku.el \
	lisp/org-toc.el \
	lisp/org-track.el \
	lisp/org-velocity.el \
	lisp/org-wikinodes.el \
	lisp/org-xhtml.el \
	lisp/org2rem.el \
	lisp/orgtbl-sqlinsert.el \
	lisp/test-org-export-preproc.el \
	odt/BasicODConverter/BasicODConverter-0.8.0.oxt \
	odt/BasicODConverter/Filters.bas \
	odt/BasicODConverter/Main.bas \
	odt/etc/schema/od-manifest-schema-v1.2-cs01.rnc \
	odt/etc/schema/od-schema-v1.2-cs01.rnc \
	odt/etc/schema/schemas.xml \
	odt/README.org \
	README \
	scripts/dir2org.zsh \
	scripts/ditaa.jar \
	scripts/org2hpda \
	scripts/StartOzServer.oz \
	scripts/staticmathjax/application.ini \
	scripts/staticmathjax/chrome/chrome.manifest \
	scripts/staticmathjax/chrome/content/main.js \
	scripts/staticmathjax/chrome/content/main.xul \
	scripts/staticmathjax/defaults/preferences/prefs.js \
	scripts/staticmathjax/README.org \
	scripts/staticmathjax/README.txt \

post-patch:
	@${REINPLACE_CMD} -i .pv 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/Makefile
	${SED} 's|\(Org Mode\):|\1 (${PORTVERSION}):|; \
	    s|\(File: \)org,|\1${INFO},|; \
	    s|(org)|(${INFO})|' ${WRKSRC}/doc/org > ${WRKSRC}/doc/${INFO}.info

post-install:
	${INSTALL} -d ${DOCSDIR} \
	    ${DOCSDIR}/contrib/babel/langs \
	    ${DOCSDIR}/contrib/doc \
	    ${DOCSDIR}/contrib/lisp \
	    ${DOCSDIR}/contrib/odt/BasicODConverter \
	    ${DOCSDIR}/contrib/odt/etc/schema \
	    ${DOCSDIR}/contrib/scripts/staticmathjax/chrome/content \
	    ${DOCSDIR}/contrib/scripts/staticmathjax/defaults/preferences
.for i in ${CONTRIBS}
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${DOCSDIR}/contrib/$$(dirname ${i})
.endfor
.if !defined(NOPORTDOCS)
.for i in org.pdf orgcard.pdf orgguide.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
