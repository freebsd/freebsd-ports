# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	alsa-lib
PORTVERSION=	1.0.22
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-${USE_LINUX}-

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture libraries (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/etc/asound.conf:${PORTSDIR}/audio/alsa-lib

CONFLICTS=	linux-alsa-lib-[0-9]* linux-f8-alsa-lib-[0-9]* linux-f10-alsa-lib-[0-9]*

BRANDELF_FILES=	usr/bin/aserver

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_RPM=	yes
RPMVERSION=	3.el6
USE_LDCONFIG=	yes

# We will use native configuration file, so delete a linux one
post-extract:
	@${RM} -r ${WRKSRC}/etc

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	@${LN} -fs ${LOCALBASE}/etc/asound.conf ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
