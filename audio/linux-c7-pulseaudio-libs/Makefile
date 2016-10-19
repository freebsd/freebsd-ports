# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	pulseaudio-libs
PORTVERSION=	6.0
CATEGORIES=	audio linux
LIB_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-glib2-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}
SRC_DISTFILES=	pulseaudio-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for PulseAudio clients (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	7.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	dbuslibs libasyncns libsndfile tcp_wrappers-libs xorglibs
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../pulseaudio/pkg-descr

post-patch:
	@${RM} ${WRKSRC}/etc/pulse/client.conf.orig \
		${WRKSRC}/usr/lib/pulseaudio/libpulsedsp.la \
		${WRKSRC}/usr/lib/pulseaudio/libpulsecommon-6.0.la \
		${WRKSRC}/usr/lib64/pulseaudio/libpulsedsp.la \
		${WRKSRC}/usr/lib64/pulseaudio/libpulsecommon-6.0.la

.include <bsd.port.mk>
