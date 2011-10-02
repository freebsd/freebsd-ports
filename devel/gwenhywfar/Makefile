# New ports collection makefile for:	gwenhywfar
# Date created:		2005-05-05
# Whom:			Peter Cornelius <pcc.at.gmx.net>
#
# $FreeBSD$
#

PORTNAME=	gwenhywfar
PORTVERSION=	4.3.0
CATEGORIES=	devel net security
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=01&release=64&file=01&dummy=/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Multi-platform helper library for networking and security applications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	gcrypt.18:${PORTSDIR}/security/libgcrypt \
		gnutls.47:${PORTSDIR}/security/gnutls

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack pkgconfig

OPTIONS=	APIDOC "Full API documentation (requires Doxygen)" off \
		MEMDEBUG "Enable memory debugger statistic" off \
		FOX16 "Build FOX 1.6 GUI" off \
		GTK2 "Build GTK 2.x GUI (for GnuCash)" on \
		QT4 "Build Qt 4.x GUI (for KMyMoney)" on

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes" \
		--with-guis="${_GWEN_GUIS}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	GWEN_SHLIB_VER="${GWEN_SHLIB_VER}"
USE_LDCONFIG=	yes

GWEN_SHLIB_VER=	60

.include <bsd.port.options.mk>

.if !defined(NOPORTDOCS) && defined(WITH_APIDOC)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		dot:${PORTSDIR}/graphics/graphviz
CONFIGURE_ARGS+=--enable-full-doc
PORTDOCS=	apidoc
.endif

.if defined(WITH_MEMDEBUG)
CONFIGURE_ARGS+=--enable-memtrace
.endif

.if defined(WITH_FOX16)
LIB_DEPENDS+=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16
PLIST_SUB+=	WITH_FOX16=""
_GWEN_GUIS+=	fox16
.else
PLIST_SUB+=	WITH_FOX16="@comment "
.endif

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
PLIST_SUB+=	WITH_GTK2=""
_GWEN_GUIS+=	gtk2
.else
PLIST_SUB+=	WITH_GTK2="@comment "
.endif

.if defined(WITH_QT4)
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build uic_build
QT_NONSTANDARD=	yes
PLIST_SUB+=	WITH_QT4=""
_GWEN_GUIS+=	qt4
.else
PLIST_SUB+=	WITH_QT4="@comment "
.endif

post-build:
.if !defined(NOPORTDOCS) && defined(WITH_APIDOC)
	@cd ${WRKSRC} && ${GMAKE} srcdoc
.endif

post-install:
.if !defined(NOPORTDOCS) && defined(WITH_APIDOC)
	${MKDIR} ${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} \* ${DOCSDIR}/apidoc
.endif

.include <bsd.port.mk>
