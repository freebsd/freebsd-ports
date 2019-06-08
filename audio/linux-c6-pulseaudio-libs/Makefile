# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	pulseaudio
PORTVERSION=	0.9.21
DISTVERSIONSUFFIX=	-26.el6
PORTREVISION=	7
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-libs
LIB_DISTNAMES=	${LINUXNAME}-${DISTVERSIONFULL} \
		${LINUXNAME}-glib2-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for PulseAudio clients (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	${PORTNAME}${PKGNAMESUFFIX}
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	dbuslibs libasyncns libsndfile tcp_wrappers-libs xorglibs
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
