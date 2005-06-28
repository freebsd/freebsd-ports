# New ports collection makefile for:	xmms-gbsplay
# Date created:				25 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	xmms-

COMMENT=	A XMMS plugin for playing Nintendo Game Boy(TM) audio

MASTERDIR=	${.CURDIR}/../gbsplay

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms \
		gbsplay:${PORTSDIR}/audio/gbsplay

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	glib12

CONFIGURE_ARGS=	--disable-nas

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PLIST_FILES=	lib/xmms/Input/gbsxmms.so

post-extract:
	@${RM} -f ${WRKSRC}/po/subdir.mk

gbsplay-post-patch:
	@${REINPLACE_CMD} -e \
		's|`which xmms-config`||; \
		 s|\(xmms-config\)|${X11BASE}/bin/\1|g; \
		 s|`which glib-config`||; \
		 s|glib-config|${GLIB_CONFIG}|g; \
		 /LOCALE_PREFIX/ s|$$localedir|${LOCALBASE}/share/locale|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^objs += $$(objs_gbsplay) $$(objs_gbsinfo)||; \
		 s|^dsts += gbsplay gbsinfo||; \
		 /^default:/ s|$$(mans)||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gbsxmms.so ${PREFIX}/lib/xmms/Input

.include "${MASTERDIR}/Makefile"
