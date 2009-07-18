# New ports collection makefile for:	vips
# Date created:		19 December 2003
# Whom:			Lev Serebryakov <lev@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vips
PORTVERSION=	7.14.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.vips.ecs.soton.ac.uk/supported/${PORTVERSION:R}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Free image processing system

OPTIONS+=	LIBOIL	"Use liboil for CPU-optimized primitives" on
# Making Python a proper option awaits portmgr's resolving the current
# chicken-and-egg problem of OPTIONS vs. USE_* knobs
#OPTIONS+=	PYTHON	"Create Python bindings" ${PYPRESENT}
DISTNAME=	${PORTNAME}-${PORTVERSION}

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		exif:${PORTSDIR}/graphics/libexif	\
		tiff:${PORTSDIR}/graphics/tiff \
		GraphicsMagick:${PORTSDIR}/graphics/GraphicsMagick \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		png:${PORTSDIR}/graphics/png \
		lcms:${PORTSDIR}/graphics/lcms

PYPRESENT!=	which python > /dev/null && echo on || echo off
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_GNOME=	gnomehack glib20 pkgconfig pango libxml2
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

post-configure:
	${REINPLACE_CMD} -Ee 's,^(G?MSGFMT = *)$$,\1${LOCALBASE}/bin/msgfmt,g' \
		${WRKSRC}/po/Makefile

.if defined(NOPORTDOCS)
# Don't extract doc/ subdirectory - the simplest way:
EXTRACT_AFTER_ARGS=	| ${TAR} -xpf - --exclude doc
post-install:
	${RMDIR} ${DOCSDIR}
.else
# Don't extract html-ized man-pages in either case:
EXTRACT_AFTER_ARGS=	| ${TAR} -xpf - --exclude doc/html/man
.endif
PLIST_SUB+=	VERSION=${PORTVERSION:R}

CONFIGURE_ENV+=	MAGICK_CFLAGS="-I${LOCALBASE}/include/GraphicsMagick"
CONFIGURE_ARGS+=--without-x --mandir=${PREFIX}/man --with-magickpackage=GraphicsMagick
.for p in tiff jpeg zip png
CONFIGURE_ARGS+=--with-$p-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=--with-$p-libraries=${LOCALBASE}/lib
.endfor

# This is used to generate the list of man-pages and MLINKS. It
# looks through the available man-pages and filters out those,
# which consist of ``.so another/page''. Instead of installing
# these stubs, we handle them as MLINKS.
# Only use this target, if upgrading the port.
.PHONY:	Makefile.man
Makefile.man:
	@${ECHO_MSG} "# This file is auto-generated" > $@
	${FIND} ${WRKSRC}/ -type f -name '*.[13]' | ${XARGS} ${AWK} '	\
		/\.so/ {	\
			page=substr($$2, 6, 100);	\
			sub(".*/", "", FILENAME);	\
			print "MLINKS+=\t" page "\t" FILENAME;	\
			nextfile;	\
		} {	\
			sub(".*/", "", FILENAME);	\
			ext = FILENAME;	\
			sub(".*\\.", "", ext);	\
			print "MAN" ext "+=\t" FILENAME;	\
			nextfile;	\
		}' >> $@

.include "Makefile.man"

.include <bsd.port.pre.mk>

.if defined(WITH_LIBOIL)
LIB_DEPENDS+=	oil:${PORTSDIR}/devel/liboil
.else
CONFIGURE_ARGS+=	--without-liboil
.endif

.include <bsd.port.post.mk>
