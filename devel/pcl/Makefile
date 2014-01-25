# Created by: Manuel Giraud <manuel.giraud@gmail.com>
# $FreeBSD$

PORTNAME=	pcl
PORTVERSION=	1.6
CATEGORIES=	devel
MASTER_SITES=	http://www.xmailserver.org/

MAINTAINER=	manuel.giraud@gmail.com
COMMENT=	Portable Coroutine Library

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION}

BROKEN_sparc64=	Does not compile on sparc64

.include <bsd.port.mk>
