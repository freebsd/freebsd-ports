PORTNAME=	pulseaudio
PORTVERSION=	15.0
DISTVERSIONSUFFIX=	-3.el9
PORTREVISION=	2
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for PulseAudio clients (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://pulseaudio.org/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	dbuslibs libasyncns libsndfile systemd-libs xorglibs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL} \
		${PORTNAME}${PKGNAMESUFFIX}-glib2-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${RM} ${WRKSRC}/etc/pulse/client.conf.orig

.include <bsd.port.mk>
