# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-utils
PORTVERSION=	1.1.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/utils/ \
		GENTOO

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	ALSA compatibility utils

LICENSE=	GPLv2+

LIB_DEPENDS=	libasound.so:audio/alsa-lib
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		gmake localbase shebangfix tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-udev-rules-dir="\$${prefix}/lib/udev"
SHEBANG_FILES=	alsa-info/alsa-info.sh alsaconf/alsaconf.in bat/alsabat-test.sh
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${.CURDIR}/../alsa-lib/files

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	BAT MANPAGES NLS
OPTIONS_DEFAULT=BAT MANPAGES

BAT_DESC=	Basic Audio Tester support
BAT_LIB_DEPENDS=libfftw3.so:math/fftw3
BAT_CONFIGURE_ENABLE=bat

MANPAGES_BUILD_DEPENDS=	xmlto:textproc/xmlto
MANPAGES_CONFIGURE_ENABLE=xmlto

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls
NLS_LIBS=	-lintl

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/s/-ldl//g; /LIBRT/s/-lrt//g;' \
		${WRKSRC}/configure
	${FIND} -E ${WRKSRC} -type f -regex \
		'.*\.([[:digit:]]|spec\.in|csv|xml)' -exec \
		${REINPLACE_CMD} -i .pathfix.bak \
		-e 's|/usr/share|${PREFIX}/share|g' \
		-e 's|/etc/asound\.conf|${LOCALBASE}&|g' {} +

.include <bsd.port.mk>
