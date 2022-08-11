PORTNAME=	wavegain
PORTVERSION=	1.2.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.rarewares.org/files/others/
DISTNAME=	${PORTNAME}-${PORTVERSION}srcs${EXTRACT_SUFFIX}

MAINTAINER=	darcsis@gmail.com
COMMENT=	Program that applies ReplayGain to wave files

LICENSE=	LGPL21

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses x86 assembly

USES=		gmake dos2unix zip

PLIST_FILES=	bin/wavegain

WRKSRC=		${WRKDIR}/WaveGain-${PORTVERSION}

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} *.c -o ${PORTNAME} \
		-DHAVE_CONFIG_H -lm -lsndfile -L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
