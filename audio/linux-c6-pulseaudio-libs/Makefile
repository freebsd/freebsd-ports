# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	pulseaudio-libs
PORTVERSION=	0.9.21
PORTREVISION=	6
CATEGORIES=	audio linux
LIB_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-glib2-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for PulseAudio clients (Linux CentOS ${LINUX_DIST_VER})

RPMVERSION=	24.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	dbuslibs libasyncns libsndfile tcp_wrappers-libs xorglibs
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../pulseaudio/pkg-descr
SRC_DISTFILES=	pulseaudio-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
