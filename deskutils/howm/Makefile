# New ports collection makefile for:	howm
# Date created:		28 Dec 2003
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	howm
PORTVERSION=	1.2.1
CATEGORIES=	deskutils
MASTER_SITES=	http://howm.sourceforge.jp/a/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Write fragmentarily and read collectively

GNU_CONFIGURE=	yes
EMACS_PORT_NAME?=	emacs21
ELISP=		action-lock.el bcomp.el cheat-font-lock.el \
		howm-common.el howm-date.el howm-menu.el howm-misc.el \
		howm-mode.el howm-reminder.el \
		howm-version.el howm-view.el howm.el riffle.el
.if defined(WITH_COMPILED_ELISP)
PLIST_SUB=	COMPILED_ELISP=""
.else
PLIST_SUB=	COMPILED_ELISP="@comment "
.endif

do-install:
	cd ${WRKSRC}; ${INSTALL_DATA} *.el ${PREFIX}/${EMACS_SITE_LISPDIR}
.if defined(WITH_COMPILED_ELISP)
	cd ${WRKSRC}; ${INSTALL_DATA} *.elc ${PREFIX}/${EMACS_SITE_LISPDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}/ja ${EXAMPLESDIR}/en
	cd ${WRKSRC}; ${INSTALL_DATA} ja/0* ${EXAMPLESDIR}/ja
	cd ${WRKSRC}; ${INSTALL_DATA} en/0* ${EXAMPLESDIR}/en
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.png ${DOCSDIR}

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
