# New ports collection makefile for:	emacs-wget
# Date Created:		6 Nov. 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	emacs-wget
PORTVERSION=	0.3.2
CATEGORIES=	ftp www
MASTER_SITES=	http://isweb22.infoseek.co.jp/computer/pop-club/emacs/emacs-wget/

MAINTAINER=	yoichi@FreeBSD.org

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/emacs/site-lisp/wget
	${INSTALL_DATA} ${WRKSRC}/*.el ${PREFIX}/share/emacs/site-lisp/wget
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README.ja USAGE.ja
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
