# New ports collection makefile for:  gcin
# Date created:                   Feb 18 2004
# Whom:                           Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	gcin
DISTVERSION=	1.4.5.pre2
PORTREVISION=	1
CATEGORIES=	chinese textproc gnome
MASTER_SITES=	http://www.csie.nctu.edu.tw/~cp76/gcin/download/:main \
  		http://cle.linux.org.tw/gcin/download/:main \
		LOCAL/chinsan/gcin:main
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:main
EXTRACT_ONLY=	gcin-${PORTVERSION}.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A traditional chinese input utility in X

CONFLICTS=	zh-gcin-[0-9]*
NO_LATEST_LINK=	yes

BUILD_DEPENDS+=	${LOCALBASE}/include/anthy/anthy.h:${PORTSDIR}/japanese/anthy
USE_BZIP2=	YES
HAS_CONFIGURE=	YES
USE_GNOME=	gtk20
USE_GMAKE=	YES
USE_XORG=	xtst
INSTALLS_ICONS=	YES
USE_LDCONFIG=	YES

ONLY_FOR_ARCHS=	i386

OPTIONS=	ANTHY		"enable Japanese anthy IM module" off \
		BOSHIAMY	"enable Boshiamy Input Method" on \
		QT_IM_MODULE	"enable QT IM module" on

MAN1=		gcin.1 gcin2tab.1 gcin-gb-toggle.1 gcin-kbm-toggle.1 \
		gcin-message.1 gcin-setup.1 gtab-merge.1 juyin-learn.1 \
		phoa2d.1 sim2trad.1 tsa2d32.1 tslearn.1

WRKSRC=		${WRKDIR}/gcin-${DISTVERSION}

IGNORE=		is older than chinese/gcin

.include <bsd.port.options.mk>

.if defined(WITH_QT_IM_MODULE)
USE_QT_VER=	4
QT_COMPONENTS=	inputmethods qmake_build moc_build corelib gui
LIB_DEPENDS+=	mng:${PORTSDIR}/graphics/libmng
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build
.endif

.if defined(WITH_ANTHY)
BUILD_DEPENDS+=	${LOCALBASE}/include/anthy/anthy.h:${PORTSDIR}/japanese/anthy
.endif

.if defined(WITH_BOSHIAMY)
MASTER_SITES+=	http://cle.linux.org.tw/~edt1023/gcin/:boshiamy \
		LOCAL/chinsan/gcin:boshiamy \
		http://edt1023.sayya.org/gcin/:boshiamy
DISTFILES+=	${BOSHIAMY_FILE}:boshiamy
BOSHIAMY_FILE=	noseeing-12.tar.gz
post-extract:
	@${TAR} -C ${WRKSRC}/data/ -zxf ${DISTDIR}/${BOSHIAMY_FILE} \
		noseeing.cin
	@${TAR} -C ${WRKSRC}/scripts/ -zxf ${DISTDIR}/${BOSHIAMY_FILE} \
	  	noseeadd.rb
	@${REINPLACE_CMD} -e 's,cj.gtab,cj.gtab noseeing.gtab,' \
		${WRKSRC}/data/Makefile
	@${REINPLACE_CMD} -e 's,noseeing-inst,noseeing-inst noseeadd.rb,' \
		${WRKSRC}/scripts/Makefile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,&,,; 1 s,bash,sh,; \
		s,QT_IM_DIR=/usr,QT_IM_DIR=$$prefix,; \
		s,mandir=$$datadir,mandir=$$prefix,; \
		s,/usr/share,$$prefix/share,; s,libdir)\/gcin,libdir),; \
		s,/usr/lib/qt4/plugins/lib,${PREFIX}/lib/qt4/plugins,; \
		131 s,QT,QT4,; \
		s,gcc,$$CC,; s,gcin-$$GCIN_VERSION,gcin,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,\/usr\/share,$$(prefix)\/share,;' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/local,/usr,g' \
		${WRKSRC}/gtk-im/Makefile ${WRKSRC}/menu/Makefile
	@${REINPLACE_CMD} -e 's,/usr/lib,${LOCALBASE}/lib,g; \
		s,/usr/include,${LOCALBASE}/include,g; \
		s,Xft2/X11/Xft,X11/Xft,' ${WRKSRC}/qt-im/Makefile
	@${REINPLACE_CMD} -e 's,modify-XIM ,,; 8,10 d' \
		${WRKSRC}/scripts/Makefile
	@${REINPLACE_CMD} -e 's,bash,sh,; s/&//; s,/opt/gnome,${LOCALBASE},;' \
		${WRKSRC}/scripts/utf8-edit ${WRKSRC}/scripts/gcin-user-setup \
		${WRKSRC}/scripts/gtab.append_prepare
	@${REINPLACE_CMD} -e 's,bash,sh,; s/&//; 12,13 s/=/ /; \
		s/export/setenv/; s/mozilla-firefox/firefox3/;' \
		${WRKSRC}/scripts/html-browser
	@${REINPLACE_CMD} -e 's,wget,fetch,' ${WRKSRC}/scripts/noseeing-inst
	@${REINPLACE_CMD} -e 's,gcin-im-client.h,im-client/gcin-im-client.h,;' \
		${WRKSRC}/gtk-im/gtkimcontextgcin.c
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' \
		${WRKSRC}/IMdkit/lib/Makefile ${WRKSRC}/Makefile \
		${WRKSRC}/qt-im/Makefile ${WRKSRC}/scripts/modify-XIM \
		${WRKSRC}/scripts/utf8-edit
	@${REINPLACE_CMD} -e '/make/ d' ${WRKSRC}/IMdkit/lib/Makefile

.if defined(WITH_BOSHIAMY)
PLIST_SUB+=	BOSHIAMY=""
.else
PLIST_SUB+=	BOSHIAMY="@comment "
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
