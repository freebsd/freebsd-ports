# New ports collection makefile for:	slime
# Date created:		13 Nov 2004
# Whom:			Dominic Mitchell
#
# $FreeBSD$
#

PORTNAME=	slime
PORTVERSION=	20090407
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Superior Lisp Interaction Mode for Emacs

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_EMACS=	yes

SLIME_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/slime

.if !defined(NOPORTDOCS)
INFO=		slime
PORTDOCS=	ChangeLog HACKING NEWS PROBLEMS README
.endif

do-build:
	cd ${WRKSRC}/doc && ${GMAKE} slime.info
	cd ${WRKSRC} && ${EMACS_CMD} -batch \
		-eval '(setq load-path (cons nil load-path))' \
		-f batch-byte-compile *.el

do-install:
	@${MKDIR} ${SLIME_LISPDIR}
	@${MKDIR} ${SLIME_LISPDIR}/contrib

	cd ${WRKSRC}/ && ${INSTALL_DATA} *.elc *.el *.lisp ${SLIME_LISPDIR}/
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} *.el *.lisp \
		${SLIME_LISPDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${SLIME_LISPDIR}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/slime.info ${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/contrib/README ${DOCSDIR}/README-contrib
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/slime-refcard.pdf ${DOCSDIR}/
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/slime-small.pdf ${DOCSDIR}/
.endif

	@${ECHO_MSG}
	@${ECHO_MSG} "========================================================"
	@${ECHO_MSG} "To activate SLIME put the following code into ~/.emacs:"
	@${ECHO_MSG} '(setq inferior-lisp-program "PATH_TO_YOUR_LISP_BINARY")'
	@${ECHO_MSG} "(add-to-list 'load-path \"${SLIME_LISPDIR}\""
	@${ECHO_MSG} '	"${SLIME_LISPDIR}/contrib")'
	@${ECHO_MSG} "(require 'slime)"
	@${ECHO_MSG} "(slime-setup '(slime-repl))"
	@${ECHO_MSG} "========================================================"
	@${ECHO_MSG}

.include <bsd.port.mk>
