# New ports collection makefile for:	emacs20-dl-canna
# Version required:	1.0
# Date created:		10 October 1998
# Whom:			shige
#
# $Id: Makefile,v 1.1.1.1 1999/01/11 14:19:16 kuriyama Exp $
#

DISTNAME=	emacs-canna-1.0
PKGNAME=	ja-emacs20-dl-canna-1.0
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/GNU/elisp/emacs-20-dl/

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna
BUILD_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR} \
		/nonexistent:${EMACSDL_DIR}:configure
RUN_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR} \
		${LOCALBASE}/share/emacs/20.3/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-emacs20

WRKSRC=		${WRKDIR}/dl-canna-1.0
MAKE_ENV=	PREFIX=${PREFIX}
MAKE_ARGS=	EMACS_SRC_DIR=${WRKDIRPREFIX}${EMACSDL_DIR}/work/emacs-${EMACS_VER}
PLIST_SUB=	EMACS_VER=${EMACS_VER} LISPDIR=${LISPDIR} DOCDIR=${DOCDIR}

EMACS_VER=	20.3
EMACSDL_DIR=	${PORTSDIR}/editors/emacs20-dl
MODULEDIR=	${LOCALBASE}/libexec/emacs/${EMACS_VER}/i386--freebsd/
LISPDIR=	share/emacs/site-lisp
DOCDIR=		share/doc/emacs20-dl-canna

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/canna.so ${MODULEDIR}/canna.so
	@${INSTALL_DATA} ${WRKSRC}/canna.el ${PREFIX}/${LISPDIR}/canna.el

post-install:
.if !defined(NOPORTDOCS)
	@[ -d ${PREFIX}/${DOCDIR} ] || ${MKDIR} ${PREFIX}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.ja ${PREFIX}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/${DOCDIR}
.endif

.include <bsd.port.mk>
