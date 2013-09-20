# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-lib
PORTVERSION=	1.0.26
CATEGORIES=	audio
MASTER_SITES=	ALSA/lib \
		GENTOO/distfiles

MAINTAINER=	aragon@phat.za.net
COMMENT=	ALSA compatibility library

NO_STAGE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-aload --disable-python \
		--with-pkgconfdir="${PREFIX}/libdata/pkgconfig"

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/ { s/-ldl//g; s/-lrt//g; }' \
		-e '/-D_GNU_SOURCE/d' \
		-e '/lt_cv_dlopen/s/-ldl//g' ${WRKSRC}/configure
	${REINPLACE_CMD} '/LIBADD/s/-ldl//g' \
		${WRKSRC}/modules/mixer/simple/Makefile.in
	${REINPLACE_CMD} 's|/etc|${PREFIX}&|g' \
		${WRKSRC}/src/conf/alsa.conf

post-install:
	${INSTALL_DATA} ${FILESDIR}/asound.conf.sample ${PREFIX}/etc
	@if [ ! -f ${PREFIX}/etc/asound.conf ]; then \
		${CP} -p ${PREFIX}/etc/asound.conf.sample \
			${PREFIX}/etc/asound.conf ; \
	fi

.include <bsd.port.mk>
