# $FreeBSD$

PORTNAME=	pulseaudio-libs-glib2
PORTVERSION=	0.9.21
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for PulseAudio clients with a GLib based application (Linux CentOS ${LINUX_DIST_VER})

RUN_DEPENDS=	linux-${USE_LINUX}-openssl>0:${PORTSDIR}/security/linux-c6-openssl

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	pulseaudio-libs
RPMVERSION=	17.el6
USE_LDCONFIG=	yes
DESCR=		${PORTSDIR}/audio/pulseaudio/pkg-descr

SRC_DISTFILES=	pulseaudio-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
