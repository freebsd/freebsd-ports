# New ports collection makefile for:	pinot
# Date created:		2006-11-19
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	pinot
PORTVERSION=	0.94
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_BERLIOS}
#MASTER_SITES=	http://www.chez.com/colinf/pinot/	\
#		http://amra.dyndns.org/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Personal search and metasearch for the Free Desktop

BUILD_DEPENDS=	update-desktop-database:${PORTSDIR}/devel/desktop-file-utils
LIB_DEPENDS=	xapian.21:${PORTSDIR}/databases/xapian-core	\
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24	\
		textcat.0:${PORTSDIR}/textproc/libtextcat	\
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib	\
		xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26	\
		boost_thread.4:${PORTSDIR}/devel/boost		\
		exif.12:${PORTSDIR}/graphics/libexif		\
		gmime-2.4:${PORTSDIR}/mail/gmime24		\
		tag.6:${PORTSDIR}/audio/taglib			\
		curl.5:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info	\
		antiword:${PORTSDIR}/textproc/antiword			\
		xdg-open:${PORTSDIR}/devel/xdg-utils			\
		pdftotext:${PORTSDIR}/graphics/xpdf			\
		catppt:${PORTSDIR}/textproc/catdoc			\
		unzip:${PORTSDIR}/archivers/unzip			\
		unrtf:${PORTSDIR}/textproc/unrtf			\
		catdvi:${PORTSDIR}/print/catdvi

LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-http=curl --with-ssl=${OPENSSLBASE} --enable-libarchive
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" MKDIR_P="${MKDIR}"

USE_XORG=	pixman
USE_GETTEXT=	yes
USE_SQLITE=	3
USE_PYTHON=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	${PREFIX}/lib/pinot/backends ${PREFIX}/lib/pinot/filters

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

INSTALLS_ICONS=	yes

PLIST_SUB=	DESKBAR_MOD="${LDESKBAR_MOD}"

MAN1=		pinot-dbus-daemon.1 pinot-index.1 pinot-label.1 pinot-search.1 pinot.1

PORTDOCS=	AUTHORS ChangeLog ChangeLog-dijon INSTALL NEWS README TODO

LM2FIX=		textcat_conf.txt textcat3_conf.txt IndexSearch/Google/Makefile.in
SHR2FIX=	Core/pinot-search.1 README
UL2FIX=		Utils/xdgmime/xdgmime.c

LDESKBAR_MOD=	lib/deskbar-applet/modules-2.20-compatible
DESKBAR_MOD=	${PREFIX}/${LDESKBAR_MOD}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700041
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif

post-extract:
# remove pre-generated messages catalogs
	${FIND} ${WRKSRC}/po -name "*.gmo" -delete

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|'	\
		${LM2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|'	\
		${UL2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|'	\
		${SHR2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|Icon=pinot.png|Icon=pinot|g' \
		${WRKSRC}/*.desktop

post-install:
	${TOUCH} ${DATADIR}/stopwords/.empty_file
	${MKDIR} ${DESKBAR_MOD}
.for pyscript in pinot-module
	${INSTALL_DATA} ${WRKSRC}/scripts/python/${pyscript}.py ${DESKBAR_MOD}
.endfor
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DESKBAR_MOD}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DESKBAR_MOD}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py		\
		${PREFIX}/lib/deskbar-applet/handlers
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py	\
		${PREFIX}/lib/deskbar-applet/handlers
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if ${OSVERSION} < 700041
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
