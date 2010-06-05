# New ports collection makefile for:   alsa-lib
# Date created:                June 29, 2009
# Whom:                        Aragon Gouveia <aragon@phat.za.net>
#
# $FreeBSD$
#

PORTNAME=	alsa-lib
PORTVERSION=	1.0.23
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.silug.org/pub/alsa/lib/ \
		ftp://gd.tuwien.ac.at/opsys/linux/alsa/lib/ \
		http://dl.ambiweb.de/mirrors/ftp.alsa-project.org/lib/ \
		ftp://ftp.alsa-project.org/pub/lib/

MAINTAINER=	aragon@phat.za.net
COMMENT=	ALSA compatibility library
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --disable-aload --disable-python

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/ { s/-ldl//g; s/-lrt//g; }' \
		-e '/lt_cv_dlopen/s/-ldl//g' ${WRKSRC}/configure
	${REINPLACE_CMD} '/LIBADD/s/-ldl//g' \
		${WRKSRC}/modules/mixer/simple/Makefile.in
	${REINPLACE_CMD} 's|/etc|${PREFIX}&|g' \
		${WRKSRC}/src/conf/alsa.conf
	${REINPLACE_CMD} \
		'/pkgconfigdir/s|$$(libdir)|$$(prefix)/libdata|g' \
		${WRKSRC}/utils/Makefile.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/asound.conf.sample ${PREFIX}/etc
	@if [ ! -f ${PREFIX}/etc/asound.conf ]; then \
		${CP} -p ${PREFIX}/etc/asound.conf.sample \
			${PREFIX}/etc/asound.conf ; \
	fi

.include <bsd.port.mk>
