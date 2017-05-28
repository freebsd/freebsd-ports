# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	pulseaudio
PORTVERSION=	6.0
PORTREVISION=	2
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-libs
LIB_DISTNAMES=	${LINUXNAME}-${DISTVERSIONFULL} \
		${LINUXNAME}-glib2-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for PulseAudio clients (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${LINUXNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	${PORTNAME}${PKGNAMESUFFIX}
RPMVERSION=	9.el7_3
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	dbuslibs libasyncns libsndfile tcp_wrappers-libs xorglibs
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${RM} ${WRKSRC}/etc/pulse/client.conf.orig \
		${WRKSRC}/usr/lib/pulseaudio/libpulsedsp.la \
		${WRKSRC}/usr/lib/pulseaudio/libpulsecommon-6.0.la \
		${WRKSRC}/usr/lib64/pulseaudio/libpulsedsp.la \
		${WRKSRC}/usr/lib64/pulseaudio/libpulsecommon-6.0.la

.include <bsd.port.mk>
