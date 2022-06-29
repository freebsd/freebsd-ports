# Created by: Sergey Akifyev <asa@gascom.ru>

PORTNAME=	libmad
PORTVERSION=	0.16.2
CATEGORIES=	audio

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Libmad library (part of MAD project)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe pathfix

USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	underbit

USE_GITHUB=	yes
GH_ACCOUNT=	tenacityteam

.include <bsd.port.mk>
