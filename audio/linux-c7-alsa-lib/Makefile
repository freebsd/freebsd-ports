# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	alsa-lib
PORTVERSION=	1.0.28
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture libraries (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	GPLv3

RUN_DEPENDS=	alsa-lib>0:audio/alsa-lib

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

USES=		linux:c7
USE_LINUX_RPM=	yes
RPMVERSION=	2.el7
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
	${RM} ${STAGEDIR}${PREFIX}/usr/lib64/alsa-lib/smixer/smixer-ac97.la
	${RM} ${STAGEDIR}${PREFIX}/usr/lib64/alsa-lib/smixer/smixer-hda.la
	${RM} ${STAGEDIR}${PREFIX}/usr/lib64/alsa-lib/smixer/smixer-sbase.la

.include <bsd.port.mk>
