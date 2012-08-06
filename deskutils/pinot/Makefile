# New ports collection makefile for:	pinot
# Date created:		2006-11-19
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	pinot
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
#MASTER_SITES=	http://colinf.chez.com/pinot/
#		http://amra.dyndns.org/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Personal search and metasearch for the Free Desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	update-desktop-database:${PORTSDIR}/devel/desktop-file-utils
LIB_DEPENDS=	xapian:${PORTSDIR}/databases/xapian-core	\
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24	\
		exttextcat-1.0:${PORTSDIR}/textproc/libexttextcat	\
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib	\
		xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26	\
		boost_thread.4:${PORTSDIR}/devel/boost-libs	\
		execinfo.1:${PORTSDIR}/devel/libexecinfo	\
		exif.12:${PORTSDIR}/graphics/libexif		\
		exiv2.12:${PORTSDIR}/graphics/exiv2		\
		gmime-2.4:${PORTSDIR}/mail/gmime24		\
		tag.1:${PORTSDIR}/audio/taglib			\
		curl.6:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info	\
		antiword:${PORTSDIR}/textproc/antiword			\
		xdg-open:${PORTSDIR}/devel/xdg-utils			\
		${LOCALBASE}/libexec/xpdf/pdftotext:${PORTSDIR}/graphics/xpdf	\
		catppt:${PORTSDIR}/textproc/catdoc			\
		unzip:${PORTSDIR}/archivers/unzip			\
		unrtf:${PORTSDIR}/textproc/unrtf			\
		catdvi:${PORTSDIR}/print/catdvi

PROJECTHOST=	${PORTNAME}-search

LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-http=curl --with-ssl=${OPENSSLBASE} --enable-libarchive	\
		--enable-mempool=no
CONFIGURE_ENV=	MKDIR_P="${MKDIR}"
CPPFLAGS+=	-I${LOCALBASE}/include

USE_DOS2UNIX=	textcat32_conf.txt
USE_XORG=	pixman
USE_GETTEXT=	yes
USE_SQLITE=	3
USE_PYTHON=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	${PREFIX}/lib/pinot/backends ${PREFIX}/lib/pinot/filters

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

.if defined(WITH_CHMLIB)
CONFIGURE_ARGS+=	--enable-chmlib=yes
PLIST_SUB+=	CHMLIB=""
.else
PLIST_SUB+=	CHMLIB="@comment "
.endif

INSTALLS_ICONS=	yes

MAN1=		pinot-dbus-daemon.1 pinot-index.1 pinot-label.1 pinot-search.1 pinot.1

PORTDOCS=	AUTHORS ChangeLog ChangeLog-dijon INSTALL NEWS README TODO

LM2FIX=		textcat_conf.txt textcat3_conf.txt textcat31_conf.txt textcat32_conf.txt
SHR2FIX=	Core/pinot-search.1 README
UL2FIX=		Utils/xdgmime/xdgmime.c

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700041
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif

post-extract:
# remove pre-generated messages catalogs
	${FIND} ${WRKSRC}/po -name "*.gmo" -delete

post-patch:
	${REINPLACE_CMD} -e \
		'/<command>/s|pdftotext|${LOCALBASE}/libexec/xpdf/pdftotext|' \
		${WRKSRC}/Tokenize/filters/external-filters.xml

pre-configure:
	${REINPLACE_CMD} -e 's|-lthr|${PTHREAD_LIBS}|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|'	\
		${LM2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|libtextcat/|libtextcat/LM/|'	\
		${WRKSRC}/textcat_conf.txt
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|'	\
		${UL2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|'	\
		${SHR2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|Icon=pinot.png|Icon=pinot|g' \
		${WRKSRC}/*.desktop

post-install:
	${TOUCH} ${DATADIR}/stopwords/.empty_file
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
