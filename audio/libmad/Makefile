# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$

PORTNAME=	libmad
PORTVERSION=	0.15.1b
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/mad/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libmad library (part of MAD project)

OPTIONS_DEFINE=	SPEED
SPEED_DESC=	Optimize for speed over accuracy

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-debugging \
		--enable-sso

SPEED_CONFIGURE_ON=	--enable-speed
SPEED_CONFIGURE_OFF=	--enable-accuracy

post-patch:
	@${SED} -e 's|%PREFIX%|${PREFIX}|g ; s|%VERSION%|${PORTVERSION}|g' \
		${FILESDIR}/mad.pc.in > ${WRKDIR}/mad.pc
	@${REINPLACE_CMD} -e 's| -fforce-mem||' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKDIR}/mad.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
