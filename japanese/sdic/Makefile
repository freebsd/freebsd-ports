# New ports collection makefile for:	sdic
# Date created:        	09 Sep 1999
# Whom:			Kazumasa Nishizawa <kazumasa@selab.tutkie.tut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	sdic
PORTVERSION=	2.1.2
CATEGORIES=	japanese elisp
MASTER_SITES=	ftp://pine.kuee.kyoto-u.ac.jp/pub/tsuchiya/sdic/

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/dict/jedict.sdic:${PORTSDIR}/japanese/edict-sdic

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=mule \
		--with-lispdir=${PREFIX}/share/emacs/site-lisp \
		--with-dictdir=${PREFIX}/share/dict
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/emacs/site-lisp
	${MKDIR} ${PREFIX}/lib/xemacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${PREFIX}/share/emacs/site-lisp
	for f in ${WRKSRC}/lisp/*.el; do \
		file=`basename $$f`; \
		${LN} -sf ${PREFIX}/share/emacs/site-lisp/$$file \
			${PREFIX}/lib/xemacs/site-lisp; \
	done

.include <bsd.port.mk>
