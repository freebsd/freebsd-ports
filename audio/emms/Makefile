# New ports collection makefile for:    emms
# Date created:		10 May 2006
# Whom:			Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	emms
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	audio elisp
MASTER_SITES=	http://www.gnu.org/software/emms/download/ \
		http://dryice.name/computer/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EMMS is the Emacs Multi-Media System

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs22

.if ${EMACS_PORT_NAME} != "emacs22"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

USE_GMAKE=	yes
MAKE_ENV+=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}
INFO=		emms
MAN1=		emms-print-metadata.1

.include <bsd.port.mk>
