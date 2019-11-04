# Created by: Loïc Bartoletti <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	codeblocks
PORTVERSION=	18.04
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://download.tuxfamily.org/bartcoding/FreeBSD/ \
		${MASTER_SITE_LOCAL}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-${SVN_REV}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Open source, cross-platform, free C/C++ IDE

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libhunspell-1.7.so:textproc/hunspell

USES=		autoreconf compiler:c++11-lang desktop-file-utils gnome \
		fam:gamin localbase gettext-runtime libtool pathfix pkgconfig \
		shared-mime-info xorg
USE_WX=		2.8
USE_GNOME=	gtk20 cairo
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG} --with-contrib-plugins=all \
		--disable-pch --with-boost-system=boost_system
PKG_CONFIG_LIBDIR=	${LOCALBASE}/libdata/pkgconfig
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

FETCH_DEPENDS+=	svn:devel/subversion
SVN_REV=	11386
SVNROOT_URI=	svn://svn.code.sf.net/p/codeblocks/code/trunk

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
. if ${COMPILER_VERSION} >= 35
CXXFLAGS+=	-Wno-undefined-bool-conversion
. endif
.endif

.if defined(MAINTAINER_MODE)
do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} ${SVNROOT_URI} ${WRKSRC}
	cd ${WRKDIR}; tar cvfz ${DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
	${CHMOD} ugo+r ${DISTDIR}/${DISTNAME}.tar.gz
	scp -p ${DISTDIR}/${DISTNAME}.tar.bz2 \
		freefall.freebsd.org:public_distfiles/
.endif # defined(MAINTAINER_MODE)

post-extract:
	${TOUCH} ${WRKSRC}/revision.m4

.include <bsd.port.post.mk>
