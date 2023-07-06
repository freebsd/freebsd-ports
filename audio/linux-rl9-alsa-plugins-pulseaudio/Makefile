PORTNAME=	alsa-plugins
PORTVERSION=	1.2.7.1
DISTVERSIONSUFFIX=	-1.el9
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-pulseaudio

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	PulseAudio plugin for ALSA (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.alsa-project.org/

LICENSE=	GPLv3

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	alsalib pulseaudio-libs
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${LN} -sf ../../../usr/share/alsa/alsa.conf.d/50-pulseaudio.conf \
		${WRKSRC}/etc/alsa/conf.d

.include <bsd.port.mk>
