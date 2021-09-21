# Created by: Sergey Akifyev <asa@gascom.ru>

PORTNAME=	libmad
PORTVERSION=	0.15.1b
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF/mad/${PORTNAME}/${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Libmad library (part of MAD project)

LICENSE=	GPLv2

USES=		cpe libtool

CONFIGURE_ARGS=	--disable-debugging --enable-sso
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

SUB_LIST=	VERSION=${PORTVERSION}
SUB_FILES=	mad.pc

CPE_VENDOR=	underbit

OPTIONS_DEFINE=	SPEED
SPEED_DESC=	Optimize for speed over accuracy

SPEED_CONFIGURE_ON=	--enable-speed
SPEED_CONFIGURE_OFF=	--enable-accuracy

post-install:
	${INSTALL_DATA} ${WRKDIR}/mad.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
