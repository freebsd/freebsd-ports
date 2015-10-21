# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-lib
PORTVERSION=	1.0.29
CATEGORIES=	audio
MASTER_SITES=	ALSA/lib \
		GENTOO

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	ALSA compatibility library

LICENSE=	LGPL21 # or any later version

USES=		libtool:keepla tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfdir="\$${prefix}/libdata/pkgconfig"
INSTALL_TARGET=	install-strip
TEST_ENV=	${MAKE_ENV} ALSA_CONFIG_PATH="${FILESDIR}/asound.conf.sample"
TEST_TARGET=	check
CPPFLAGS+=	-I${FILESDIR}

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes

PYTHON_CONFIGURE_ENABLE=python
PYTHON_USES=	python:2

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/ { s/-ldl//g; s/-lrt//g; }' \
		-e 's/python-config/${PYTHON_CMD:T}-config/g' \
		-e '/pythonlibs/s/--libs/--ldflags/' \
		-e '/-D_GNU_SOURCE/d' \
		-e '/lt_cv_dlopen/s/-ldl//g' ${WRKSRC}/configure
	${REINPLACE_CMD} '/LIBADD/s/-ldl//g' \
		${WRKSRC}/modules/mixer/simple/Makefile.in
	${REINPLACE_CMD} 's|/etc|${PREFIX}&|g' \
		${WRKSRC}/src/conf/alsa.conf

post-install:
	${INSTALL_DATA} ${FILESDIR}/asound.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
