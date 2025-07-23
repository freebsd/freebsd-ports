PORTNAME=	libmikmod
DISTVERSION=	3.3.13
CATEGORIES=	audio
MASTER_SITES=	SF/mikmod/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	neuroworker@gmail.com
COMMENT=	MikMod Sound Library
WWW=		https://mikmod.sourceforge.net/

LICENSE=	LGPL21

USES=		cmake cpe
CPE_VENDOR=	raphael_assenat
USE_LDCONFIG=	yes

CMAKE_OFF=	ENABLE_STATIC \
		ENABLE_DOC \
		ENABLE_ALSA \
		ENABLE_PULSE \
		ENABLE_SNDIO

post-patch:
	@${REINPLACE_CMD} -e 's|@LIBMIKMOD_VERSION@|${DISTVERSION}|g' \
	    ${PATCH_WRKSRC}/docs/libmikmod-config.1.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/libmikmod-config.1.in \
	    ${STAGEDIR}${PREFIX}/share/man/man1/libmikmod-config.1

.include <bsd.port.mk>
