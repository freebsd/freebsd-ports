# New ports collection makefile for:	Quack
# Date created:				24 October 2003
# Whom:					Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	quack
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	lang scheme elisp
MASTER_SITES=	http://www.neilvandyke.org/quack/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.el
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	fuyuki@nigredo.org
COMMENT=	Enhanced support for editing and running Scheme code

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

EMACS_PORT_NAME?=	emacs21

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}

ELISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile quack.el

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/quack.* ${ELISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
