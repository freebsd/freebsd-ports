# ex:ts=8
# New ports collection makefile for:	emirror
# Date created:			Apr 19, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	emirror
PORTVERSION=	2.1.20
CATEGORIES=	ftp python
MASTER_SITES=	ftp://eclipt.uni-klu.ac.at/projects/emirror/ \
		ftp://emirror.sourceforge.net/pub/emirror/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc
NO_BUILD=	yes

MAN1=	emirror.1

.include <bsd.port.mk>
