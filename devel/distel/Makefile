# New ports collection makefile for:	distel
# Date Created:				11 November 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	distel
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	devel elisp
MASTER_SITES=	http://www.bluetail.com/%7Eluke/distel/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	distel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTEL_MANUALS}
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org

BUILD_DEPENDS+=	erlc:${PORTSDIR}/lang/erlang

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	base
EMACS_PORT_NAME?=	emacs21

DISTEL_MANUALS=	distel-euc.pdf distel-euc.ps.gz
DISTEL_DOCS=	config/emacs-init-snippet.el AUTHORS ChangeLog NEWS README README.ie-session

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/c/dec32 ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}/distel
	@${INSTALL_DATA} ${WRKSRC}/elisp/*el ${PREFIX}/${EMACS_SITE_LISPDIR}/distel
	@${INSTALL_DATA} ${WRKSRC}/elisp/*elc ${PREFIX}/${EMACS_SITE_LISPDIR}/distel
	@${INSTALL_DATA} ${WRKSRC}/elisp/*elc ${PREFIX}/${EMACS_SITE_LISPDIR}/distel
	@${MKDIR} ${DOCSDIR}
	@for FILE in ${DISTEL_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${DOCSDIR}; \
	done
	@for FILE in ${DISTEL_MANUALS}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${FILE} ${DOCSDIR}; \
	done
	@${MKDIR} ${DATADIR}/ebin ${DATADIR}/src
	@${INSTALL_DATA} ${WRKSRC}/erl/*.erl ${DATADIR}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${DATADIR}/ebin

.include <bsd.port.mk>
