# Created by: Petr Holub <hopet@ics.muni.cz>
# $FreeBSD$

PORTNAME=	jrtplib
PORTVERSION=	3.11.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://research.edm.uhasselt.be/jori/jrtplib/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Object-oriented RTP library written in C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.MIT

USES=		cmake pathfix tar:bzip2
USE_LDCONFIG=	yes

PLIST_SUB=	JRTPLIB_VER="${PORTVERSION}"

.include <bsd.port.mk>
