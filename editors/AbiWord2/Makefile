# New ports collection makefile for:    AbiWord
# Date created:         3 Mar 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

# Note: this port cannot be built when the textproc/mswordview port is
# already installed, due to header file conflicts and the very broken
# AbiWord build system.

PORTNAME=	AbiWord
PORTVERSION=	1.0.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.abisource.com/downloads/Version-${PORTVERSION}/lf/
MASTER_SITE_SUBDIR=	abiword
DISTNAME=	abiword-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

# unzip is needed during the installation process
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		iconv.3:${PORTSDIR}/converters/libiconv \
		psiconv.8:${PORTSDIR}/converters/psiconv

DIST_SUBDIR=	AbiWord

WRKSRC=		${WRKDIR}/abiword-${PORTVERSION}/abi

USE_X_PREFIX=	yes
USE_AUTOMAKE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12 gnomehier
WANT_GNOME=	yes
AUTOMAKE=	${WRKSRC}/autogen.sh && ${FIXME}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv"
MAKEFILE=	GNUmakefile
FIXME=		find ${WRKSRC} -name GNUmakefile.in | xargs ${REINPLACE_CMD} -e \
		    's|[(]libdir[)]/@PACKAGE@|(datadir)/@PACKAGE@|g ; \
		     s|@DEFS@|-I${WRKSRC}/../libiconv/include @DEFS@|g' && ${TRUE}

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
.undef WITHOUT_GNOME
.undef WITHOUT_ALL
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

# bonobox bonobox_print gnomeui gal print vfs gdk_pixbuf

.if ${HAVE_GNOME:Mgnomeprint}!="" && ${HAVE_GNOME:Mgal}!="" && ${HAVE_GNOME:Mgnomevfs}!=""
USE_GNOME+=	gnomeprint gal gnomevfs
CONFIGURE_ARGS+=--enable-gnome
PKGNAMESUFFIX=	-gnome
.endif

post-patch:
	@iconv -f cp1251 -t koi8-u ${WRKSRC}/user/wp/strings/uk-UA.strings > \
		${WRKDIR}/.uk-UA.strings
	@${MV} ${WRKDIR}/.uk-UA.strings ${WRKSRC}/user/wp/strings/uk-UA.strings

pre-configure:
	@cd ${WRKSRC} && ${TOUCH} NEWS README AUTHORS ChangeLog
	@cd ${WRKSRC}/ac-helpers && ${RM} -f install-sh mkinstalldirs missing
	@${RM} -f ${WRKSRC}/configure.ac

post-install:
	@${CAT} ${PKGMESSAGE}
	@${INSTALL_DATA} ${WRKSRC}/src/pkg/linux/rpm/data/abiword.desktop \
		${PREFIX}/share/gnome/apps/Applications/abiword.desktop
	@${LN} -sf ${PREFIX}/share/AbiSuite/icons/abiword_48.png \
		${PREFIX}/share/gnome/pixmaps/abiword_48.png

.include <bsd.port.post.mk>
