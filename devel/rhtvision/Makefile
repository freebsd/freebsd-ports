# New ports collection makefile for:	rhtvision
# Date created:		18 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	rhtvision
PORTVERSION=	1.1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tvision
DISTNAME=	rhtvision-${PORTVERSION}.src

MAINTAINER=	perky@fallin.lv

WRKSRC=		${WRKDIR}/tvision
USE_GMAKE=	yes
USE_PERL5=	yes
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

.include <bsd.port.mk>
