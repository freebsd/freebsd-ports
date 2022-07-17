# Created by: Nicola Vitale <nivit@email.it>

PORTNAME=	espeak-ng
PORTVERSION=	1.51.1
PORTREVISION=	3
CATEGORIES=	audio
#MASTER_SITES=	https://github.com/espeak-ng/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Software speech synthesizer

LICENSE=	GPLv3

BUILD_DEPENDS=	ronn:textproc/rubygem-ronn
LIB_DEPENDS=	libpcaudio.so:audio/pcaudiolib

USES=		autoreconf gmake libtool localbase
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcaudiolib

CONFLICTS_INSTALL=	espeak speak

OPTIONS_DEFINE=	DOCS

pre-build:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/Makefile.am ${WRKSRC}/src/libespeak-ng/speech.h

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${RLN} ${STAGEDIR}${PREFIX}/man/man1/espeak-ng.1 \
			${STAGEDIR}${PREFIX}/man/man1/espeak.1
	${LN} -sf libespeak-ng.so ${STAGEDIR}${PREFIX}/lib/libespeak.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libespeak-ng.so*

.include <bsd.port.mk>
