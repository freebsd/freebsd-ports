# New ports collection makefile for:	navi2ch for emacs20
# Date created:		13 May 2001
# Whom:			FUJISHIMA Satsuki <sf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	navi2ch
PORTVERSION=	011027
CATEGORIES=	japanese www elisp
MASTER_SITES=	http://www.geocities.co.jp/SiliconValley-Oakland/7673/lisp/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	sf@FreeBSD.org

EMACS_PORT_NAME?=	emacs20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${EMACS_LIBDIR}/site-lisp/navi2ch

DOCDIR=		share/doc/ja/navi2ch
.if ${EMACS_PORT_NAME} == emacs20
PLIST_SUB=	XEMACS="@comment "
.elif ${EMACS_PORT_NAME} == xemacs21-mule
PLIST_SUB=	XEMACS=""
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${DOCDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
