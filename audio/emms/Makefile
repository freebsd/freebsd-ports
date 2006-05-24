# New ports collection makefile for:    emms
# Date created:		10 May 2006
# Whom:			Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	emms
PORTVERSION=	2.0
CATEGORIES=	audio elisp
MASTER_SITES=	http://www.gnu.org/software/emms/releases/ \
		http://dryice.name/computer/FreeBSD/distfiles/

MAINTAINER=	dryice@dryice.name
COMMENT=	EMMS is the Emacs Multi-Media System

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

USE_GMAKE=	yes
MAKE_ENV+=	EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}
INFO=		emms
MAN1=		emms-print-metadata.1

.include <bsd.port.mk>
