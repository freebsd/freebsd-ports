PORTNAME=	alsa-lib
PORTVERSION=	1.2.14
CATEGORIES=	audio
MASTER_SITES=	https://www.alsa-project.org/files/pub/lib/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	ALSA compatibility library
WWW=		https://www.alsa-project.org/

LICENSE=	LGPL21+

USES=		cpe gmake libtool:keepla tar:bzip2
CPE_VENDOR=	alsa-project
CPE_PRODUCT=	alsa
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfdir="\$${prefix}/libdata/pkgconfig"
CONFIGURE_ENV=	ac_cv_header_endian_h=no
INSTALL_TARGET=	install-strip
TEST_ENV=	${MAKE_ENV} \
		ALSA_CONFIG_PATH="${FILESDIR}/asound.conf.sample"
TEST_TARGET=	check
CPPFLAGS+=	-I${FILESDIR}
# Some symbols in the linker version script Versions.in are only defined when
# --enable-alisp is used at configure time. Suppress errors with lld >= 17 due
# to these undefined symbols.
LDFLAGS+=	-Wl,--undefined-version

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes

PYTHON_USES=			gettext-runtime python
PYTHON_CONFIGURE_ENABLE=	mixer-pymods python
PYTHON_BINARY_ALIAS=		python3-config=${PYTHON_CMD:T}-config

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/conf/alsa.conf

post-install:
	${INSTALL_DATA} ${FILESDIR}/asound.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
