# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	emms
PORTVERSION=	3.0
PORTREVISION=	13
CATEGORIES=	audio elisp
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Emacs Multi-Media System

LICENSE=	GPLv3

USES=		gmake
USE_EMACS=	yes
MAKE_ENV+=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}
INFO=		emms
MAN1=		emms-print-metadata.1

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} != "emacs23"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

.include <bsd.port.post.mk>
