# New ports collection makefile for:	navi2ch for emacs20
# Date created:		13 May 2001
# Whom:			FUJISHIMA Satsuki <sf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	navi2ch
PORTVERSION=	1.7.5
PORTEPOCH=	1
CATEGORIES=	japanese www elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	sf@FreeBSD.org
COMMENT=	2ch.net and 2ch-like BBS navigator for Emacsen

EMACS_PORT_NAME?=	emacs20
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
