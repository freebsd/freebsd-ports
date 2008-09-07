# New ports collection makefile for:	freepats
# Date created:		5 February 2008
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freepats
PORTVERSION=	20060219
CATEGORIES=	audio
MASTER_SITES=	http://freepats.opensrc.org/ GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free and open set of instrument patches

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} . ${DATADIR}/

.include <bsd.port.mk>
