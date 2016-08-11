# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	faac
PORTVERSION=	1.28
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio encoder

LICENSE=	GPLv2 LGPL21+ ISO
LICENSE_COMB=	multi
LICENSE_NAME_ISO=	ISO/IEC14496
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_FILE_ISO=	${WRKSRC}/README
LICENSE_PERMS_ISO=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libmp4v2.so:multimedia/mp4v2

USES=		autoreconf gmake libtool tar:bzip2
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mp4v2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

post-patch:
	@${ECHO_CMD} "" >> ${WRKSRC}/libfaac/psych.h
	@${REINPLACE_CMD} -e 's|<mp4\.h>|<mp4v2/mp4v2.h>|g' \
		${WRKSRC}/frontend/main.c

.include <bsd.port.mk>
