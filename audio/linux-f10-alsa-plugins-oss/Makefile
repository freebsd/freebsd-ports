# Created by: hashiz
# $FreeBSD$

PORTNAME=	alsa-plugins-oss
PORTVERSION=	1.0.21
PORTREVISION=	4
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	OSS plugin for ALSA (Linux Fedora 10)

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	alsalib

RPMVERSION=	3.fc10
SRC_DISTFILES=	${PORTNAME:S/-oss//}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE
USE_LDCONFIG=	yes

# We will use native configuration file, so delete a linux one
post-extract:
	@${RM} -r ${WRKSRC}/etc

.include <bsd.port.mk>
