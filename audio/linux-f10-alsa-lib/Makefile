# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD: head/audio/linux-f10-alsa-lib/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	alsa-lib
PORTVERSION=	1.0.21
PORTREVISION=	3
CATEGORIES=	audio linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture libraries (Linux Fedora 10)

RUN_DEPENDS=	${LOCALBASE}/etc/asound.conf:${PORTSDIR}/audio/alsa-lib

CONFLICTS=	linux-alsa-lib-[0-9]* linux-f8-alsa-lib-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	f10
USE_LINUX_RPM=	yes

RPMVERSION=	2.fc10
BRANDELF_FILES=	usr/bin/aserver
USE_LDCONFIG=	yes

# We will use native configuration file, so delete a linux one
post-extract:
	@${RM} -r ${WRKSRC}/etc

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	@${LN} -fs ${LOCALBASE}/etc/asound.conf ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
