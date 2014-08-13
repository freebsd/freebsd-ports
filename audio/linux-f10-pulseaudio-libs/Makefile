# Created by: avg
# $FreeBSD: head/audio/linux-f10-pulseaudio-libs/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	pulseaudio-libs
PORTVERSION=	0.9.14
CATEGORIES=	audio linux
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	netchild/rpms/${LINUX_DIST}${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for PulseAudio clients

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	4.fc10
SRC_DISTFILES=	${PORTNAME:S/-libs//}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}
USE_LDCONFIG=	yes

CONF_FILE=	etc/pulse/client.conf

pre-patch:
	@${MV} ${WRKSRC}/${CONF_FILE} ${WRKSRC}/${CONF_FILE}-dist
post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
	@if [ ! -f ${PREFIX}/${CONF_FILE} ]; then \
		${CP} -p ${STAGEDIR}${PREFIX}/${CONF_FILE}-dist ${STAGEDIR}${PREFIX}/${CONF_FILE} ; \
	fi

.include <bsd.port.mk>
