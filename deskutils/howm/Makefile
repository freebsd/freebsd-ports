# New ports collection makefile for:	howm
# Date created:		28 Dec 2003
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	howm
PORTVERSION=	1.1.0.4
CATEGORIES=	deskutils
MASTER_SITES=	http://howm.sourceforge.jp/a/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Write fragmentarily and read collectively

EMACS_PORT_NAME?=	emacs21
ELISP=		action-lock.el \
		howm-font-lock.el howm-menu.el howm-mode.el howm-view.el

do-build:
.for i in ${ELISP}
	cd ${WRKSRC}; ${EMACS_CMD} -q -batch -L . -f batch-byte-compile ${i}
.endfor

do-install:
	cd ${WRKSRC}; ${INSTALL_DATA} *.el *.elc ${PREFIX}/${EMACS_SITE_LISPDIR}
	${MKDIR} ${EXAMPLESDIR}/ja ${EXAMPLESDIR}/en
	cd ${WRKSRC}; ${INSTALL_DATA} ja/* ${EXAMPLESDIR}/ja
	cd ${WRKSRC}; ${INSTALL_DATA} en/* ${EXAMPLESDIR}/en
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} *.html *.png ${DOCSDIR}

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
