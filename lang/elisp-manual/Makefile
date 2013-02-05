# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	elisp-manual
PORTVERSION=	21.2.8
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	lang elisp
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs Lisp reference manual

DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2013-03-05

BROKEN=		overwrites files owned by editors/emacs: info/elisp.info
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./-/}
GNU_CONFIGURE=	yes
ALL_TARGET=	elisp
MAKE_ARGS=	MAKEINFO="makeinfo --no-split"

INFO=		elisp

do-install:
	${INSTALL_DATA} ${WRKSRC}/elisp ${PREFIX}/${INFO_PATH}/elisp.info

.include <bsd.port.mk>
