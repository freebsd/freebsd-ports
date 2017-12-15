# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	faac
PORTVERSION=	1.29.9.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTNAME}-${PORTVERSION:R:R}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio encoder

LICENSE=	GPLv2 LGPL21+ ISO
LICENSE_COMB=	multi
LICENSE_NAME_ISO=	ISO/IEC14496
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_FILE_ISO=	${WRKSRC}/README
LICENSE_PERMS_ISO=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake libtool
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
