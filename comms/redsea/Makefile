# $FreeBSD$

PORTNAME=	redsea
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.1
CATEGORIES=	comms

MAINTAINER=	morrand276@gmail.com
COMMENT=	Lightweight command-line FM-RDS decoder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=	autoreconf:build compiler:c++14-lang iconv localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	windytan

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/redsea ${DOCSDIR}/README.md

OPTIONS_DEFINE=		DEMOD TMC
OPTIONS_DEFAULT=	DEMOD TMC

DEMOD_DESC=	Demodulation support via comms/liquid-dsp
TMC_DESC=	Decoding support for TMC traffic messages (may slow building)

DEMOD_CONFIGURE_WITH=	liquid
DEMOD_LIB_DEPENDS=	libliquid.so:comms/liquid-dsp
TMC_CONFIGURE_ENABLE=	tmc

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -i

.include <bsd.port.mk>
