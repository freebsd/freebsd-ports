# Created by: Shen Chuan-Hsing
# $FreeBSD$

PORTNAME=	gcin
PORTVERSION=	2.8.2
PORTREVISION=	1
CATEGORIES=	chinese textproc gnome
MASTER_SITES=	http://hyperrate.com/gcin-source/
EXTRACT_ONLY=	gcin-${PORTVERSION}.tar.xz

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Traditional Chinese input utility in X

LICENSE=	LGPL21

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--use_gtk3=N --use_qt3=N
USE_GNOME=	gtk20
USES=		gmake pkgconfig tar:xz
USE_XORG=	x11 xtst xext
INSTALLS_ICONS=	YES
USE_LDCONFIG=	YES
OPTIONS_DEFINE=	ANTHY QT_IM_MODULE DOCS
ANTHY_DESC=	Japanese anthy IM module
QT_IM_MODULE_DESC=	QT IM module

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT_IM_MODULE}
USE_QT4=	inputmethods qmake_build moc_build corelib gui
LIB_DEPENDS+=	libmng.so:${PORTSDIR}/graphics/libmng
PLIST_SUB+=	QT_IM_MODULE=""
.else
CONFIGURE_ARGS+=	--use_qt4=N
PLIST_SUB+=	QT_IM_MODULE="@comment "
.endif

.if ${PORT_OPTIONS:MANTHY}
BUILD_DEPENDS+=	${LOCALBASE}/include/anthy/anthy.h:${PORTSDIR}/japanese/anthy
LIB_DEPENDS+=	libanthy.so:${PORTSDIR}/japanese/anthy
PLIST_SUB+=	ANTHY_MODULE=""
.else
CONFIGURE_ARGS+=	--use_anthy=N
PLIST_SUB+=	ANTHY_MODULE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,&,,; 1 s,##!/bin/bash,#!/bin/sh,; \
		s,QT_IM_DIR=/usr,QT_IM_DIR=$$prefix,g; \
		s,QT4_IM_DIR=/usr,QT4_IM_DIR=$$prefix,g; \
		s,-ldl,,; \
		s,mandir=$$datadir,mandir=$$prefix,; \
		s,/usr/share,$$prefix/share,; \
		s,/usr/bin/moc,${LOCALBASE}/bin/moc-qt4,; \
		1, 300 s,gcc,$$CC,; s,gcin-$$GCIN_VERSION,gcin,; \
		/GCIN_DEBUG/ d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,\/usr\/share,$$(prefix)\/share,; \
		s,%%PREFIX%%,${PREFIX},;' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '94 s/gcin/gcin-setup/' ${WRKSRC}/gcin-common.cpp
	@${REINPLACE_CMD} -e 's,/usr/local,/usr,g' \
		${WRKSRC}/gtk-im/Makefile ${WRKSRC}/menu/Makefile
	@${REINPLACE_CMD} -e 's,modify-XIM ,,; 8,10 d' \
		${WRKSRC}/scripts/Makefile
	@${REINPLACE_CMD} -e 's,bash,sh,; s/&//; s,/opt/gnome,${LOCALBASE},;' \
		${WRKSRC}/scripts/utf8-edit ${WRKSRC}/scripts/gcin-user-setup \
		${WRKSRC}/scripts/gtab.append_prepare \
		${WRKSRC}/scripts/tsin-gtab-import \
		${WRKSRC}/scripts/tsin-gtab-edit
	@${REINPLACE_CMD} -e 's,bash,sh,; s/&//; 12,13 s/=/ /; \
		s/export/setenv/; s/$$UTF8ED/xdg-open/' \
		${WRKSRC}/scripts/html-browser
	@${REINPLACE_CMD} -e 's,gcin-im-client.h,im-client/gcin-im-client.h,;' \
		${WRKSRC}/gtk-im/gtkimcontextgcin.c
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' \
		${WRKSRC}/IMdkit/lib/Makefile ${WRKSRC}/Makefile \
		${WRKSRC}/qt-im/Makefile ${WRKSRC}/scripts/modify-XIM \
		${WRKSRC}/scripts/utf8-edit
	@${REINPLACE_CMD} -e '/make/ d' ${WRKSRC}/IMdkit/lib/Makefile
	@${REINPLACE_CMD} -e 's,/usr/X11R6/lib,${LOCALBASE}/lib,' ${WRKSRC}/im-client/Makefile
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} '/install.*DOC_DIR/d' ${WRKSRC}/Makefile
.endif

post-build:
.if !defined(DEBUG_FLAGS)
	@${FIND} ${WRKSRC} -name "*.so*" | ${XARGS} ${STRIP_CMD}
.endif

post-install:
.if !defined(DEBUG_FLAGS)
.for f in gcin* gtab-merge juyin-learn phoa2* sim2trad trad2sim ts-edit tsa2d32 tsd2a32 tsin2gtab-phrase tslearn
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
.endif

.include <bsd.port.mk>
