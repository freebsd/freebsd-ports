# New ports collection makefile for:   clips
# Date created:        8 July 2001
# Whom:                Douglas Anestad <yotta@dougdidit.com>
#
# $FreeBSD$
#

PORTNAME=	clips
PORTVERSION=	6.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.ghgcorp.com/clips/download/other/
DISTNAME=	clips6
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A productive development and delivery expert system tool

BROKEN=	Unfetchable
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2006-12-01

USE_AUTOTOOLS=	autoconf:213
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
