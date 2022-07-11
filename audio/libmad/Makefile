# Created by: Sergey Akifyev <asa@gascom.ru>

PORTNAME=	libmad
PORTVERSION=	0.16.2
CATEGORIES=	audio

PATCH_SITES=	https://github.com/tenacityteam/libmad/commit/
PATCHFILES=	9ec2efa6ba4bfaed7805867077d3a67daa022331.patch:-p1

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
