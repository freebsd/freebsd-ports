# ex:ts=8
# New ports collection makefile for:	libAfterBase
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libafterbase
PORTVERSION=	0.81
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	afterstep
DISTNAME=	libAfterBase-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sharedlibs --with-x
WRKSRC=		${WRKDIR}/libAfterBase
INSTALLS_SHLIB=	yes

post-install:
	@${MV} -f ${PREFIX}/lib/libAfterBase.so.0.81 ${PREFIX}/lib/libAfterBase.so.0

.include <bsd.port.mk>
