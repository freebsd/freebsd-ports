# New ports collection makefile for:	gkrellkam2
# Date Created:		24 Nov 2002
# Whom:			Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
# $Id: Makefile,v 1.1.1.1 2002/11/24 03:37:56 jylefort Exp $
#

PORTNAME=		gkrellkam
PORTVERSION=		2.0.0
PORTREVISION=	1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM plugin that display thumbnails of periodically updated images

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAN5=		gkrellkam-list.5

MAKE_ENV+=	MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.mk>
