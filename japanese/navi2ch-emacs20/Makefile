# New ports collection makefile for:	navi2ch for emacs20
# Date created:		13 May 2001
# Whom:			FUJISHIMA Satsuki <sf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	navi2ch
PORTVERSION=	1.4
PORTEPOCH=	1
CATEGORIES=	japanese www elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	sf@FreeBSD.org

EMACS_PORT_NAME?=	emacs20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${LISPDIR}/navi2ch

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${DOCDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
