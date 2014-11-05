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

CONFLICTS=	linux-alsa-lib-[0-9]* linux-f8-alsa-lib-[0-9]* linux-f10-alsa-lib-[0-9]*

BRANDELF_FILES=	usr/bin/aserver

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
RPMVERSION=	3.el6
USE_LDCONFIG=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/alsa-lib/smixer/smixer-ac97.la
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/alsa-lib/smixer/smixer-hda.la
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/alsa-lib/smixer/smixer-sbase.la

.include <bsd.port.mk>
