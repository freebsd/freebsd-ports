# $FreeBSD$

PORTNAME=	timewarrior
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	https://taskwarrior.org/download/
DISTNAME=	timew-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Track time from the command line

LICENSE=	MIT

USES=		cmake compiler:c++11-lang
CMAKE_ARGS+=	-DTIMEW_DOCDIR=${DOCSDIR}

OPTIONS_SUB=	yes

.include <bsd.port.mk>
