# New ports collection makefile for:  zh-gcin
# Date created:                   Feb 18 2004
# Whom:                           Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	gcin
PORTVERSION=	1.5.9
CATEGORIES=	chinese textproc gnome
MASTER_SITES=	http://www.csie.nctu.edu.tw/~cp76/gcin/download/:main \
		LOCAL/chinsan/gcin:main
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:main
EXTRACT_ONLY=	gcin-${PORTVERSION}.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A traditional chinese input utility in X

LICENSE=	LGPL21

USE_BZIP2=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--use_gtk3=N
USE_GNOME=	gtk20
USE_GMAKE=	YES
USE_XORG=	x11 xtst xext
INSTALLS_ICONS=	YES
USE_LDCONFIG=	YES
OPTIONS=	ANTHY		"enable Japanese anthy IM module" off \
		QT_IM_MODULE	"enable QT IM module" off

MAN1=		gcin.1 gcin-exit.1 gcin2tab.1 gcin-gb-toggle.1 gcin-kbm-toggle.1 \
		gcin-message.1 gcin-setup.1 gtab-merge.1 juyin-learn.1 \
		phoa2d.1 sim2trad.1 tsa2d32.1 tslearn.1

.include <bsd.port.options.mk>

.if defined(WITH_QT_IM_MODULE)
USE_QT_VER=	4
QT_COMPONENTS=	inputmethods qmake_build moc_build corelib gui
LIB_DEPENDS+=	mng:${PORTSDIR}/graphics/libmng
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile
.endif

.if defined(WITH_ANTHY)
BUILD_DEPENDS+=	${LOCALBASE}/include/anthy/anthy.h:${PORTSDIR}/japanese/anthy
RUN_DEPENDS+=	${LOCALBASE}/include/anthy/anthy.h:${PORTSDIR}/japanese/anthy
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,&,,; 1 s,bash,sh,; \
		s,QT_IM_DIR=/usr,QT_IM_DIR=$$prefix,g; \
		s,QT4_IM_DIR=/usr,QT4_IM_DIR=$$prefix,g; \
		s,mandir=$$datadir,mandir=$$prefix,; \
		s,/usr/share,$$prefix/share,; \
		1, 300 s,gcc,$$CC,; s,gcin-$$GCIN_VERSION,gcin,; \
		/GCIN_DEBUG/ d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,\/usr\/share,$$(prefix)\/share,;' \
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
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} '/install.*DOC_DIR/d' ${WRKSRC}/Makefile
.endif

.if defined(WITH_QT_IM_MODULE)
PLIST_SUB+=	QT_IM_MODULE=""
.else
PLIST_SUB+=	QT_IM_MODULE="@comment "
.endif

post-build:
.if !defined(DEBUG_FLAGS)
	@${FIND} ${WRKSRC} -name "*.so*" | ${XARGS} ${STRIP_CMD}
.endif

post-install:
.if !defined(DEBUG_FLAGS)
.for f in gcin* gtab-merge juyin-learn phoa2* sim2trad trad2sim ts*
	@${STRIP_CMD} ${PREFIX}/bin/${f}
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in Changelog.html README.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'

.include <bsd.port.post.mk>
