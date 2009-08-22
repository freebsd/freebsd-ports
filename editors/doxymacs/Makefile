# Ports collection makefile for:	w3 on Emacs21
# Date created:				21 December 2003
# Whom:					Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	doxymacs
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	editors elisp
MASTER_SITES=	SF \
		http://dryice.name/computer/FreeBSD/distfiles/


MAINTAINER=	dryice@dryice.name
COMMENT=	Doxymacs is Doxygen + {X}Emacs

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21
BUILD_DEPENDS=		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/w3/w3.el:${PORTSDIR}/www/w3-4 \
			xmllint:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=		${BUILD_DEPENDS}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
