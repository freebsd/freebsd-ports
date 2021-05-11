# Created by: Aragon Gouveia <aragon@phat.za.net>

PORTNAME=	alsa-lib
PORTVERSION=	1.2.2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/lib/ \
		GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ALSA compatibility library

LICENSE=	LGPL21+

USES=		cpe libtool:keepla tar:bzip2
CPE_VENDOR=	alsa
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfdir="\$${prefix}/libdata/pkgconfig"
CONFIGURE_ENV=	ac_cv_header_endian_h=no
INSTALL_TARGET=	install-strip
TEST_ENV=	${MAKE_ENV} \
		ALSA_CONFIG_PATH="${FILESDIR}/asound.conf.sample"
TEST_TARGET=	check
CPPFLAGS+=	-I${FILESDIR}

OPTIONS_DEFINE=		PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=			gettext-runtime python
PYTHON_CONFIGURE_ENABLE=	mixer-pymods python
PYTHON_BINARY_ALIAS=		python3-config=${PYTHON_CMD:T}-config

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/conf/alsa.conf

post-install:
	${INSTALL_DATA} ${FILESDIR}/asound.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
