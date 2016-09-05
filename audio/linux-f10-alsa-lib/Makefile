# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alsa-lib
PORTVERSION=	1.0.21
PORTREVISION=	5
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture libraries (Linux Fedora 10)

RUN_DEPENDS=	alsa-lib>0:audio/alsa-lib

CONFLICTS=	linux-alsa-lib-[0-9]* linux-f8-alsa-lib-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes

RPMVERSION=	2.fc10
USE_LDCONFIG=	yes

# We will use native configuration file, so delete a linux one
post-extract:
	@${RM} -r ${WRKSRC}/etc

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${LN} -fs ${LOCALBASE}/etc/asound.conf ${STAGEDIR}${PREFIX}/etc
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/alsa-lib/smixer/smixer-ac97.la
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/alsa-lib/smixer/smixer-hda.la
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/alsa-lib/smixer/smixer-sbase.la

.include <bsd.port.mk>
