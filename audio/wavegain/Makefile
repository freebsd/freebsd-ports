PORTNAME=	wavegain
DISTVERSION=	1.3.1
CATEGORIES=	audio
MASTER_SITES=	http://www.rarewares.org/files/others/
DISTNAME=	${PORTNAME}-${DISTVERSION}srcs

MAINTAINER=	darcsis@gmail.com
COMMENT=	Program that applies ReplayGain to wave files
WWW=		https://www.rarewares.org/others.html

LICENSE=	LGPL21

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses x86 assembly

USES=		dos2unix zip

WRKSRC=		${WRKDIR}/WaveGain-${DISTVERSION}

PLIST_FILES=	bin/wavegain

do-build:
	(cd ${WRKSRC} && ${SETENVI} ${CC} *.c -o ${PORTNAME} \
	    ${CFLAGS} -DHAVE_CONFIG_H ${LDFLAGS} -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
