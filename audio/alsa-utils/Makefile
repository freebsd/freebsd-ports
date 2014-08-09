# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-utils
PORTVERSION=	1.0.28
CATEGORIES=	audio
MASTER_SITES=	ALSA/utils \
		GENTOO/distfiles

MAINTAINER=	jbeich@vfemail.net
COMMENT=	ALSA compatibility utils

LICENSE=	GPLv2 # or any later version

LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins

USES=		gmake tar:bzip2 shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-udev-rules-dir="\$${prefix}/lib/udev"
SHEBANG_FILES=	alsaconf/alsaconf.in
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include -I${.CURDIR}/../alsa-lib/files
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	xmlto:${PORTSDIR}/textproc/xmlto
MANPAGES_CONFIGURE_ENABLE=xmlto

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls
NLS_LDFLAGS=	-lintl

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/s/-ldl//g; /LIBRT/s/-lrt//g;' \
		${WRKSRC}/configure
	${FIND} -E ${WRKSRC} -type f -regex \
		'.*\.([[:digit:]]|spec\.in|csv|xml)' -exec \
		${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		-e 's|/etc/asound\.conf|${LOCALBASE}&|g' {} +

.include <bsd.port.mk>
