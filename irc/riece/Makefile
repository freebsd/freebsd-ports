# New ports collection makefile for:	riece
# Date created: 	30 May 2004
# Whom:			KIMURA Yasuhiro <yasu@utahime.org>
#
# $FreeBSD$

PORTNAME=	riece
PORTVERSION=	7.0.0
PORTEPOCH=	1
CATEGORIES=	irc elisp
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yasu@utahime.org
COMMENT=	IRC client for Emacs

USE_EMACS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
USE_GMAKE=	yes
USE_RUBY=	yes
RUBY_VER=	1.8

INFO=	riece-en riece-ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS NEWS.ja README README.ja doc/HACKING doc/HACKING.ja
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
