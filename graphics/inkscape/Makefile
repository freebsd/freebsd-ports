# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	inkscape
PORTVERSION=	0.91
PORTREVISION=	4
CATEGORIES=	graphics gnome
MASTER_SITES=	https://inkscape.global.ssl.fastly.net/media/resources/file/ \
		LOCAL/kwm

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Full featured open source SVG editor

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libgc.so:${PORTSDIR}/devel/boehm-gc \
		libgsl.so:${PORTSDIR}/math/gsl \
		libgtkspell.so:${PORTSDIR}/textproc/gtkspell \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libpng.so:${PORTSDIR}/graphics/png \
		libMagick++-6.so:${PORTSDIR}/graphics/ImageMagick
#RUN_DEPENDS=	p5-XML-XQL>=0:${PORTSDIR}/textproc/p5-XML-XQL

USE_GNOME=	gtkmm24 intlhack libxslt
USES=		compiler:c++0x cpe desktop-file-utils gettext gmake iconv \
		libtool pathfix perl5 pkgconfig python:run shebangfix tar:bzip2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-gnome-vfs

python_CMD?=	${LOCALBASE}/bin/python2
SHEBANG_FILES=	cxxtest/cxxtestgen.pl share/extensions/*.p[lm] \
		share/extensions/*.py share/extensions/genpofiles.sh

OPTIONS_DEFINE=	POPPLER OPENMP VISIO CDR DBUS WPG
OPTIONS_DEFAULT=POPPLER VISIO CDR WPG
OPTIONS_SUB=	yes

CDR_DESC=		Support for CorelDRAW diagrams
CDR_CONFIGURE_ENABLE=	cdr
CDR_LIB_DEPENDS=	librevenge-stream-0.0.so:${PORTSDIR}/textproc/librevenge \
			libcdr-0.1.so:${PORTSDIR}/graphics/libcdr01

DBUS_CONFIGURE_ENABLE=	dbusapi
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

OPENMP_USES=		compiler:openmp
OPENMP_USES_OFF=	compiler:features

POPPLER_DESC=		PDF preview rendering
POPPLER_CONFIGURE_ENABLE=	poppler-cairo
#POPPLER_CONFIGURE_ON=	--enable-poppler-cairo
#POPPLER_CONFIGURE_OFF=	--enable-poppler-cairo=no
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib

VISIO_DESC=		Support for Microsoft Visio diagrams
VISIO_CONFIGURE_ENABLE=	visio
VISIO_LIB_DEPENDS=	librevenge-stream-0.0.so:${PORTSDIR}/textproc/librevenge \
			libvisio-0.1.so:${PORTSDIR}/textproc/libvisio01

WPG_DESC=		Support for WordPerfect graphics
WPG_CONFIGURE_ENABLE=	wpg
WPG_LIB_DEPENDS=	libwpg-0.2.so:${PORTSDIR}/graphics/libwpg

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CPPFLAGS+=	-Wno-mismatched-tags -Wno-unknown-attributes
.endif

# Base clang 3.4.1 in FreeBSD 9.3 fails to compile this code on i386
# but base clang 3.4.1 in FreeBSD 10.1 succeeds.  The difference *appears*
# to be the patch applied in r271597 (head) / r271739 (stable/10).  The
# latter happened shortly before 10.1 was branched.
.if ${ARCH} == i386 && ${OPSYS} == FreeBSD && ${OSVERSION} < 1001000 && \
    ( ${COMPILER_TYPE} == clang || ${ALT_COMPILER_TYPE} == clang )
BUILD_DEPENDS+=	clang34:${PORTSDIR}/lang/clang34
CPP=    ${LOCALBASE}/bin/clang-cpp34
CC=     ${LOCALBASE}/bin/clang34
CXX=    ${LOCALBASE}/bin/clang++34
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' \
	    	${WRKSRC}/configure
#.if ! ${PORT_OPTIONS:MPOPPLER}
#	@${REINPLACE_CMD} -e 's|poppler|pdisable|g' \
#		${WRKSRC}/configure
#.endif

.include <bsd.port.post.mk>
