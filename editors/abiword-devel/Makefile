# New ports collection makefile for:    AbiWord2
# Date created:         22 February 2003
# Whom:                 Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AbiWord2
PORTVERSION=	1.1.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.abisource.com/downloads/Version-${PORTVERSION}/lf/
MASTER_SITE_SUBDIR=	abiword
DISTNAME=	abiword-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open-source, cross-platform WYSIWYG word processor

# unzip is needed during the installation process
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		iconv.3:${PORTSDIR}/converters/libiconv \
		gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		fribidi.0:${PORTSDIR}/converters/fribidi

DIST_SUBDIR=	AbiWord

WRKSRC=		${WRKDIR}/abiword-${PORTVERSION}/abi

USE_X_PREFIX=	yes
USE_AUTOMAKE=	yes
USE_AUTOMAKE_VER=14
USE_AUTOCONF_VER=213
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehier
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -liconv"
CONFIGURE_ARGS=	--enable-xft
MAKEFILE=	GNUmakefile

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/wv.h)
BROKEN=	"This port cannot be built when textproc/wv is installed because of a header conflict.  Please remove textproc/wv, and resume the build.  If textproc/wv is no longer installed, please remove ${LOCALBASE}/include/wv.h, and resume the AbiWord build"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%AUTOMAKE%%|${AUTOMAKE}|g ; \
		s|%%ACLOCAL%%|${ACLOCAL}|g ; \
		s|%%AUTOCONF%%|${AUTOCONF}|g' ${WRKSRC}/autogen.sh

pre-configure:
	@cd ${WRKSRC} && ${TOUCH} NEWS README AUTHORS ChangeLog INSTALL
	@cd ${WRKSRC}/ac-helpers && ${RM} -f install-sh mkinstalldirs missing
	@${RM} -f ${WRKSRC}/configure.ac
	@cd ${WRKSRC} && ./autogen.sh && ${TRUE}
	@${FIND} ${WRKSRC} -name GNUmakefile.in | xargs ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/@PACKAGE@|(datadir)/@PACKAGE@|g ; \
		 s|@DEFS@|-I${WRKSRC}/../libiconv/include @DEFS@|g' && ${TRUE}

post-install:
	@${CAT} ${PKGMESSAGE}
	@${INSTALL_DATA} ${WRKSRC}/src/pkg/linux/rpm/data/abiword.desktop \
		${PREFIX}/share/gnome/apps/Applications/abiword.desktop
	@${LN} -sf ${PREFIX}/share/AbiSuite-2.0/icons/abiword_48.png \
		${PREFIX}/share/gnome/pixmaps/abiword_48.png

.include <bsd.port.post.mk>
