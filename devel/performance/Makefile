PORTNAME=	performance
PORTVERSION=	0.5.0
PORTREVISION=	7
CATEGORIES=	devel gnustep
MASTER_SITES=	GNUSTEP/libs
DISTNAME=	Performance-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Help improve the performance of GNUstep applications

LICENSE=	LGPL3

BROKEN_aarch64=		fails to build: gmake[2]: No rule to make target 'Performance/dependencies', needed by 'internal-doc-all_'.  Stop.
BROKEN_armv7=		fails to build: gmake[2]: No rule to make target 'Performance/dependencies', needed by 'internal-doc-all_'.  Stop.
BROKEN_powerpc64=	fails to build: gmake[2]: No rule to make target 'Performance/dependencies', needed by 'internal-doc-all_'.  Stop.
BROKEN_FreeBSD_11=	fails to build: gmake[2]: No rule to make target 'Performance/dependencies', needed by 'internal-doc-all_'.  Stop.

USES=		gnustep
USE_GNUSTEP=	base build
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

.include <bsd.port.mk>
