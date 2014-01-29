# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-lib
PORTVERSION=	1.0.27.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ALSA/lib \
		GENTOO/distfiles

MAINTAINER=	aragon@phat.za.net
COMMENT=	ALSA compatibility library

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfdir="\$${prefix}/libdata/pkgconfig"

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	${OPTIONS_DEFINE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	2
.else
CONFIGURE_ARGS+=--disable-python
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/ { s/-ldl//g; s/-lrt//g; }' \
		-e 's/python-config/${PYTHON_CMD:T}-config/g' \
		-e '/-D_GNU_SOURCE/d' \
		-e '/lt_cv_dlopen/s/-ldl//g' ${WRKSRC}/configure
	${REINPLACE_CMD} '/LIBADD/s/-ldl//g' \
		${WRKSRC}/modules/mixer/simple/Makefile.in
	${REINPLACE_CMD} 's|/etc|${PREFIX}&|g' \
		${WRKSRC}/src/conf/alsa.conf

post-install:
	${INSTALL_DATA} ${FILESDIR}/asound.conf.sample ${STAGEDIR}${PREFIX}/etc
	@if [ ! -f ${PREFIX}/etc/asound.conf ]; then \
		${CP} -p ${STAGEDIR}${PREFIX}/etc/asound.conf.sample \
			${STAGEDIR}${PREFIX}/etc/asound.conf ; \
	fi

.include <bsd.port.mk>
