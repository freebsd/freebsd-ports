# New ports collection makefile for:    AbiWord
# Date created:         3 Mar 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AbiWord
PORTVERSION=	1.0.3
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

.if exists(${LOCALBASE}/include/wv.h)
BROKEN=	"This port cannot be built when textproc/wv is installed because of a header conflict.  Please remove textproc/wv, and resume the build.  If textproc/wv is no longer installed, please remove ${LOCALBASE}/include/wv.h, and resume the AbiWord build"
.endif

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
