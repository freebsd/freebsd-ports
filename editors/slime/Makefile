# New ports collection makefile for:	slime
# Date created:		13 Nov 2004
# Whom:			Dominic Mitchell
#
# $FreeBSD$
#

PORTNAME=	slime
PORTVERSION=	1.2.1
CATEGORIES=	editors elisp
MASTER_SITES=	http://common-lisp.net/project/slime/

MAINTAINER=	dom@happygiraffe.net
COMMENT=	Superior Lisp Interaction Mode for Emacs

USE_GMAKE=	yes
EMACS_PORT_NAME?=	emacs21

INFO=		slime
PORTDOCS=	ChangeLog HACKING NEWS PROBLEMS README
SLIME_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/slime

do-build:
	cd ${WRKSRC}/doc && ${GMAKE} slime.info
	cd ${WRKSRC} && ${EMACS_CMD} -batch \
		-eval '(setq load-path (cons nil load-path))' \
		-f batch-byte-compile *.el

pre-install:
	@${MKDIR} ${SLIME_LISPDIR}

do-install:
	cd ${INSTALL_WRKSRC}; \
		${INSTALL_DATA} ChangeLog ${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.el ${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.elc ${SLIME_LISPDIR}; \
		${INSTALL_DATA} *.lisp ${SLIME_LISPDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/slime.info ${PREFIX}/${INFO_PATH}
	install-info ${PREFIX}/info/slime.info ${PREFIX}/info/dir

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for F in ${PORTDOCS}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${F} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
