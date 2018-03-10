# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	gbsplay
PORTVERSION=	0.0.8
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XMMS plugin for playing Nintendo Game Boy(TM) audio

LICENSE=	GPLv2

BUILD_DEPENDS=	xmms:multimedia/xmms
RUN_DEPENDS=	xmms:multimedia/xmms

USE_GNOME=	glib12
USE_GCC=	any
HAS_CONFIGURE=	yes
USES=		gmake
USE_CSTD=	gnu89

OPTIONS_DEFINE=	NLS

NLS_CONFIGURE_OFF=	--disable-i18n
NLS_USES=		gettext-runtime

CONFIGURE_ARGS=	--disable-nas --prefix=${PREFIX}

PLIST_FILES=	lib/xmms/Input/gbsxmms.so

post-extract:
	@${RM} ${WRKSRC}/po/subdir.mk

post-patch:
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
	@${REINPLACE_CMD} -e 's|^\(default.*\)test|\1|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e \
		'/^need_include\ /d; \
		468s|char argc|int argc|; \
		s|/usr/local/include|${LOCALBASE}/include|; \
		s|/usr/local/lib|${LOCALBASE}/lib|; \
		s|/usr/X11R6/include||; \
		s|/usr/X11R6/lib||; \
		s|/usr/X11/lib|${LOCALBASE}/lib|; \
		s|/usr/lib/X11|${LOCALBASE}/lib/X11|; \
		s|-Os||; s|-pipe||; s|-fomit-frame-pointer||; \
		s|-march=$$ARCH||' \
		${WRKSRC}/configure

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Input
	${INSTALL_PROGRAM} ${WRKSRC}/gbsxmms.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
