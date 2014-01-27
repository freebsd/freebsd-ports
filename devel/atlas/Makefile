# Created by: Oliver Lehmann <lehmann@ans-netz.de>
# $FreeBSD$

PORTNAME=	Atlas
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/OldFiles
DISTNAME=	${PORTNAME}-C++-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	C++ reference implementation of the Atlas protocol

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=	pathfix
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	YES
USE_BZIP2=	YES
MAKE_ARGS=	docdir=${DOCSDIR}

.include <bsd.port.mk>
