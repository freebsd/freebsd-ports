# New ports collection makefile for:	navi2ch for emacs20
# Date created:		13 May 2001
# Whom:			FUJISHIMA Satsuki <sf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	navi2ch
PORTVERSION=	1.7.5
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	japanese www elisp
MASTER_SITES=	SF
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	2ch.net and 2ch-like BBS navigator for Emacsen

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21
INFO=		navi2ch

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${LISPDIR}/navi2ch \
		--with-emacs=${EMACS_CMD}

DOCDIR=		share/doc/ja/navi2ch
PLIST_SUB=	LISPDIR=${LISPDIR}

.if ${EMACS_PORT_NAME} == xemacs21-mule
LISPDIR=	${EMACS_SITE_LISPDIR}
PLIST_SUB+=	FSF="@comment "
.else
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}
PLIST_SUB+=	FSF=""
.if !defined(WITHOUT_X11)
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/monak12.pcf.gz:${PORTSDIR}/japanese/monafonts
.endif
.endif

post-install:
	@${MKDIR} ${PREFIX}/${DOCDIR}
.if !defined(NOPORTDOCS)
.for i in ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${DOCDIR}
.endfor
.endif
	@${MKDIR} ${PREFIX}/${DOCDIR}/contrib
.for i in gikope.el navi2ch-logo.el navi2ch-migemo.el
	${INSTALL_DATA} ${WRKSRC}/contrib/$i ${PREFIX}/${DOCDIR}/contrib
.endfor

.include <bsd.port.mk>
