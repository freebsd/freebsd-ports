# New ports collection makefile for:	distel
# Date Created:				11 November 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	distel
PORTVERSION=	3.1
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	distel
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org

BUILD_DEPENDS+=	erlc:${PORTSDIR}/lang/erlang

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	base
EMACS_PORT_NAME?=	emacs21

DISTEL_DOCS=	config/emacs-init-snippet.el AUTHORS ChangeLog NEWS README README.ie-session

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/c/dec32 ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}/distel
	@${INSTALL_DATA} ${WRKSRC}/elisp/*el ${PREFIX}/${EMACS_SITE_LISPDIR}/distel
	@${INSTALL_DATA} ${WRKSRC}/elisp/*elc ${PREFIX}/${EMACS_SITE_LISPDIR}/distel
	@${INSTALL_DATA} ${WRKSRC}/elisp/*elc ${PREFIX}/${EMACS_SITE_LISPDIR}/distel
	@for FILE in ${DISTEL_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${DOCSDIR}; \
	done
	@${MKDIR} ${DATADIR}/ebin ${DATADIR}/src
	@${INSTALL_DATA} ${WRKSRC}/erl/*.erl ${DATADIR}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${DATADIR}/ebin

.include <bsd.port.mk>
