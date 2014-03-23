# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PKGNAMEPREFIX=	xmms-

COMMENT=	XMMS plugin for playing Nintendo Game Boy(TM) audio

MASTERDIR=	${.CURDIR}/../gbsplay

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms \
		gbsplay:${PORTSDIR}/audio/gbsplay

USE_GNOME=	glib12
USE_GCC=	any

CONFIGURE_ARGS=	--disable-nas

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PLIST_FILES=	lib/xmms/Input/gbsxmms.so

post-extract:
	@${RM} -f ${WRKSRC}/po/subdir.mk

gbsplay-post-patch:
	@${REINPLACE_CMD} -e \
		's|`which xmms-config`||; \
		 s|\(xmms-config\)|${LOCALBASE}/bin/\1|g; \
		 s|`which glib-config`||; \
		 s|glib-config|${GLIB_CONFIG}|g; \
		 /LOCALE_PREFIX/ s|$$localedir|${LOCALBASE}/share/locale|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^objs += $$(objs_gbsplay) $$(objs_gbsinfo)||; \
		 s|^dsts += gbsplay gbsinfo||; \
		 /^default:/ s|$$(mans)||' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Input
	${INSTALL_PROGRAM} ${WRKSRC}/gbsxmms.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Input

.include "${MASTERDIR}/Makefile"
