# New ports collection makefile for:	riece
# Date created: 	30 May 2004
# Whom:			KIMURA Yasuhiro <yasu@utahime.org>
#
# $FreeBSD$

PORTNAME=	riece
PORTVERSION=	1.0.8
PORTEPOCH=	1
CATEGORIES=	irc elisp
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yasu@utahime.org
COMMENT=	IRC client for Emacs

EMACS_PORT_NAME?=	emacs21
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
USE_GMAKE=	yes

INFO=	riece-en riece-ja

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
