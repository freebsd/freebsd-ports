# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	pulseaudio-libs
PORTVERSION=	0.9.21
PORTREVISION=	3
CATEGORIES=	audio linux
DISTFILES:=	# hack
LIB_DISTFILES=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-glib2-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}



MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for PulseAudio clients (Linux CentOS ${LINUX_DIST_VER})

USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	dbuslibs libasyncns libsndfile tcp_wrappers-libs xorglibs

RPMVERSION=	21.el6
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/pulseaudio-${PORTVERSION}
DESCR=		${.CURDIR}/../pulseaudio/pkg-descr
SRC_DISTFILES=	pulseaudio-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

post-extract:
	@${RM} -r ${WRKSRC}/usr/bin ${WRKSRC}/etc/rc.d ${WRKSRC}/etc/sysconfig

.include <bsd.port.mk>
