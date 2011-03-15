# New ports collection makefile for:	emacs-wget
# Date Created:		6 Nov. 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	emacs-wget
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	ftp www elisp
MASTER_SITES=	http://pop-club.hp.infoseek.co.jp/emacs/emacs-wget/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple front-end to wget on Emacsen

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/emacs/site-lisp/wget
.for i in wget wget-sysdep w3-wget w3m-wget
	${INSTALL_DATA} ${WRKSRC}/${i}.el ${PREFIX}/share/emacs/site-lisp/wget
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README README.ja USAGE USAGE.ja
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
