PORTNAME=	faad2
PORTVERSION=	2.10.0
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio decoder

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe gmake libtool localbase:ldflags
CPE_VENDOR=	audiocoding
CPE_PRODUCT=	freeware_advanced_audio_decoder_2

INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes
LDFLAGS+=	-lpthread
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	knik0
GH_TAGNAME=	c626366

post-extract:
	@${LN} -sf faad.man ${WRKSRC}/frontend/faad.1

post-patch:
	@${REINPLACE_CMD} -e 's|faad.man|faad.1|g' \
		${WRKSRC}/frontend/Makefile.am
	@${REINPLACE_CMD} -e 's|^AM_CFLAGS|AM_CPPFLAGS|g ; \
		 s|-iquote |-I|g' ${WRKSRC}/libfaad/Makefile.am
	@${REINPLACE_CMD} -E -e 's|(FAAD2_VERSION +)"unknown"|\1"${PORTVERSION:R}"|' \
		${WRKSRC}/include/neaacdec.h

.include <bsd.port.mk>
