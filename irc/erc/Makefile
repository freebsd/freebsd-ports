# Ports collection makefile for: erc
# Date created:		23 February 2004
# Whom:			Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	erc
PORTVERSION=	5.1.2
CATEGORIES+=	irc elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	erc
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	karma@ez.pereslavl.ru
COMMENT=	ERC is an Emacs InternetRelayChat client

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

ERC_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

USE_GMAKE=	yes

BUILD_DEPENDS+=	\
	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/cedet/common/cedet.el:${PORTSDIR}/devel/cedet${PORTNAMESUFFIX} \
	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/bbdb/bbdb.el:${PORTSDIR}/databases/bbdb${PORTNAMESUFFIX} \
	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/emacs-chess/chess.elc:${PORTSDIR}/games/emacs-chess
RUN_DEPENDS+=	${BUILD_DEPENDS}

do-install:
	${MKDIR} ${ERC_LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${i} ${ERC_LISPDIR}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
