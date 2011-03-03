# New ports collection makefile for:	org-mode.el
# Date created:		2007-02-15
# Whom:			Kai Wang <kaiw27@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	org-mode.el
PORTVERSION=	4.64
PORTREVISION=	4
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://staff.science.uva.nl/~dominik/Tools/org/ \
		http://web.student.chalmers.se/~kaiw/FreeBSD/disfiles/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	org-${PORTVERSION}

MAINTAINER=	jhein@symmetricom.com
COMMENT=	An Emacs mode for notes and project planning

USE_EMACS=	yes
USE_GMAKE=	yes
EMACS_PORT_NAME?=	emacs21

INFO=		org

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
.endif

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "xemacs21") || \
    (${EMACS_PORT_NAME} == "xemacs21-mule") || \
    (${EMACS_PORT_NAME} == "xemacs-devel") || \
    (${EMACS_PORT_NAME} == "xemacs-devel-mule") || \
    (${EMACS_PORT_NAME} == "xemacs-mule-xft")
PLIST_SUB+=	XEMACS=""
.else
PLIST_SUB+=	XEMACS="@comment "
.endif

post-patch:
.if (${EMACS_PORT_NAME} == "xemacs21") || \
    (${EMACS_PORT_NAME} == "xemacs21-mule") || \
    (${EMACS_PORT_NAME} == "xemacs-devel") || \
    (${EMACS_PORT_NAME} == "xemacs-devel-mule") || \
    (${EMACS_PORT_NAME} == "xemacs-mule-xft")
	${REINPLACE_CMD} -Ee \
		's%^(EMACS=)emacs%\1xemacs%; \
		 s%^(lispdir =.*)/share/emacs%\1/lib/xemacs%' \
		 ${WRKSRC}/Makefile
.endif

pre-build:
.if (${EMACS_PORT_NAME} == "xemacs21") || \
    (${EMACS_PORT_NAME} == "xemacs21-mule") || \
    (${EMACS_PORT_NAME} == "xemacs-devel") || \
    (${EMACS_PORT_NAME} == "xemacs-devel-mule") || \
    (${EMACS_PORT_NAME} == "xemacs-mule-xft")
	cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX} install-noutline
.endif

post-build:
	${MV} ${WRKSRC}/org ${WRKSRC}/org.info

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${GMAKE} org.html
	${MKDIR} ${DOCSDIR}
.for i in org.html org.pdf orgcard.pdf
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
