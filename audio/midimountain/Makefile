# ex:ts=8
# New ports collection makefile for:	midimountain
# Date created:			Aug 5, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	midimountain
PORTVERSION=	0.2.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.music-community.ch/midimountain/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

USE_GTK=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes

.include <bsd.port.mk>
