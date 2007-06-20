# New ports collection makefile for:	pinot
# Date created:		2006-11-19
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$

PORTNAME=	pinot
PORTVERSION=	0.73
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_BERLIOS}
#MASTER_SITES=	http://www.chez.com/colinf/pinot/	\
#		http://amra.dyndns.org/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Personal search and metasearch for the Free Desktop

BUILD_DEPENDS=	update-desktop-database:${PORTSDIR}/devel/desktop-file-utils	\
		${SQ3THOL}:${PORTSDIR}/databases/sqlite3-threads
LIB_DEPENDS=	xapian.15:${PORTSDIR}/databases/xapian-core	\
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24	\
		textcat.0:${PORTSDIR}/textproc/libtextcat	\
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib	\
		xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26	\
		boost_thread.3:${PORTSDIR}/devel/boost		\
		gmime-2.0:${PORTSDIR}/mail/gmime2		\
		tag.5:${PORTSDIR}/audio/taglib			\
		curl.4:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info	\
		${SQ3THOL}:${PORTSDIR}/databases/sqlite3-threads	\
		antiword:${PORTSDIR}/textproc/antiword			\
		xdg-open:${PORTSDIR}/devel/xdg-utils			\
		pdftotext:${PORTSDIR}/graphics/xpdf			\
		unzip:${PORTSDIR}/archivers/unzip			\
		unrtf:${PORTSDIR}/textproc/unrtf

.if !defined(WITHOUT_SOAP)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libgsoap.a:${PORTSDIR}/devel/gsoap
CONFIGURE_ARGS+=	--with-soap=yes
.endif

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-http=curl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

USE_GETTEXT=	yes
USE_XLIB=	yes
#USE_SQLITE=	3	# Replaced by sqlite3-threads
USE_PYTHON=	yes
USE_LDCONFIG=	${PREFIX}/lib/pinot/filters

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

SQ3THOL=	${LOCALBASE}/share/sqlite3/sqlite3_with_threads-override-locks

INSTALLS_ICONS=	yes

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		pinot-dbus-daemon.1 pinot-index.1 pinot-search.1 pinot.1

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

LM2FIX=		textcat_conf.txt textcat3_conf.txt
SHR2FIX=	Search/pinot-search.1 README
UL2FIX=		Utils/xdgmime/xdgmime.c

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|'	\
		${LM2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|'	\
		${UL2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|'	\
		${SHR2FIX:S|^|${WRKSRC}/|}

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py		\
		${PREFIX}/lib/deskbar-applet/handlers
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py	\
		${PREFIX}/lib/deskbar-applet/handlers
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
