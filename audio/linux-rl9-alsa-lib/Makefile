PORTNAME=	alsa-lib
PORTVERSION=	1.2.13
DISTVERSIONSUFFIX=	-2.el9
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture libraries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.alsa-project.org/

LICENSE=	GPLv3

RUN_DEPENDS=	alsa-lib>0:audio/alsa-lib

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CONFLICTS=	linux-c7-${PORTNAME}

post-patch:
	@${RM} -r ${WRKSRC}/etc/* ${WRKSRC}/lib/modprobe.d \
		${WRKSRC}/usr/share/doc/alsa-lib

post-install:
	${LN} -sf ${LOCALBASE}/etc/asound.conf ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
