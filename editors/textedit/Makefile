# New ports collection makefile for:	textedit
# Date created:		3 January 1998
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	textedit
PORTVERSION=	1.0
CATEGORIES=	editors
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The OpenLook textedit application

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

WRKSRC=		${WRKDIR}/textedit
USE_IMAKE=	yes
MAN1=		textedit.1
PLIST_FILES=	bin/textedit

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
