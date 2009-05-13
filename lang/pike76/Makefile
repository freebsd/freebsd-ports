# New ports collection makefile for:	pike75
# Date created:		05 Feb 2004
# Whom:			kiwi@oav.net
#
# $FreeBSD$
#

PORTNAME=	pike76
PORTVERSION=	7.6.112
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	ftp://pike.ida.liu.se/pub/pike/beta/${PORTVERSION}/ \
		http://pike.ida.liu.se/pub/pike/beta/${PORTVERSION}/ \
		ftp://pike.ida.liu.se/pub/pike/all/${PORTVERSION}/ \
		http://pike.ida.liu.se/pub/pike/all/${PORTVERSION}/ \
		ftp://ftp.oav.net/pike/7.6/ \
		ftp://ftp.caudium.net/pike/official_releases/${PORTVERSION}/
DISTNAME=	Pike-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dynamic programming language with a syntax similar to C++

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		pcre.0:${PORTSDIR}/devel/pcre \
		nettle.2:${PORTSDIR}/security/nettle \
		mird.1:${PORTSDIR}/databases/mird \
		gmp.8:${PORTSDIR}/math/libgmp4

OPTIONS=	TTF "Add FreeType 1 support" on \
		FREETYPE "Add FreeType 2 support" on \
		OPT_CFLAGS "Enable additional compiliation optimizations" on \
		MYSQL "Add MySQL support" on \
		FFMPEG "Add FFmpeg support" off \
		POSTGRESQL "Add Postgres SQL support" off \
		UNIXODBC "Add UnixODBC support (incompatible with IODBC)" off \
		IODBC "Add iODBC support (incompatible with UnixODBC)" off \
		SANE "Add SANE support" off \
		PDF "Add PDF support" off \
		SVG2 "Add SVG2 support" off \
		TDS "Add FreeTDS (Sybase and MSSQL) support" off \
		FFTW "Add libFFTW support" off

MAN1=		pike.1

WANT_MESA=	yes

CONFIGURE_ENV=	CPPFLAGS+=${PTHREAD_CFLAGS}
CONFIGURE_ARGS+=	--without-debug \
		 --with-thread-library=${PTHREAD_LIBS} \
		 --with-double-precision \
		 --with-long-double-precision \
		 --disable-rpath \
		 --without-rtldebug \
		 --without-cdebug \
		 --without-copt \
		 --without-security \
		 --with-oob \
		 --without-poll \
		 --without-devpoll \
		 --with-max-fd=60000 \
		 --with-gmp \
		 --with-zlib \
		 --with-threads \
		 --with-readline \
		 --with-jpeg \
		 --with-tiff \
		 --with-gdbm \
		 --without-java \
		 --without-ssleay \
		 --without-GTK \
		 --without-gnome \
		 --without-glade \
		 --without-libglade-config \
		 --without-machine-code \
		 --prefix=${PREFIX}

MAKE_ARGS=	"CONFIGUREARGS=${CONFIGURE_ARGS}"

USE_GETTEXT=	yes
USE_BISON=	build
USE_GMAKE=	yes

# Allow building Embedded Perl
CONFIGURE_ARGS+=	--with-perl
USE_PERL5=	YES

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if defined(WITHOUT_RELOCATABLE_DUMPED_MODULES)
CONFIGURE_ARGS+=	--without-relocatable-dumped-modules
.else
CONFIGURE_ARGS+=	--with-relocatable-dumped-modules
.endif

.if defined(WITH_EXPERIMENTAL_FEATURES)
CONFIGURE_ARGS+=	--with-computed-goto \
		--with-pg \
		--with-long-long-int \
		--with-long-int \
		--with-short-int \
		--with-keypair-loop \
		--without-lock \
		--with-new-multisets
.endif

.if defined(WITH_OPT_CFLAGS)
.if (${MACHINE} == "i386")
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.else
CFLAGS+=	-ffast-math -fomit-frame-pointer
.endif
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--with-ffmpeg
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if defined(WITH_FFTW)
LIB_DEPENDS+=	fftw.2:${PORTSDIR}/math/fftw
.endif

.if defined(WITH_TTF)
LIB_DEPENDS+=	ttf.4:${PORTSDIR}/print/freetype
CONFIGURE_ARGS+=	--with-ttflib
.else
CONFIGURE_ARGS+=	--without-ttflib
.endif

.if defined(WITH_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-freetype
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if defined(WITH_MSQL)
BUILD_DEPENDS+=	msql:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-msql
.endif

.if defined(WITH_UNIXODBC)
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc
.endif

.if defined(WITH_IODBC)
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-odbc
.endif

.if !defined(WITH_UNIXODBC) && !defined(WITH_IODBC)
CONFIGURE_ARGS+=	--without-odbc
.endif

.if defined(WITH_SANE)
LIB_DEPENDS+=	sane.1:${PORTSDIR}/graphics/sane-backends
CONFIGURE_ARGS+=	--with-sane
.else
CONFIGURE_ARGS+=	--without-sane
.endif

.if defined(WITH_PDF)
LIB_DEPENDS+=	pdf.8:${PORTSDIR}/print/pdflib \
		panda.0:${PORTSDIR}/print/panda
CONFIGURE_ARGS+=	--with-libpdf --with-libpanda
.else
CONFIGURE_ARGS+=	--without-libpdf --without-libpanda
.endif

.if defined(WITH_SVG2)
LIB_DEPENDS+=	rsvg-2.10:${PORTSDIR}/graphics/librsvg2
CONFIGURE_ARGS+=	--with-svg
.else
CONFIGURE_ARGS+=	--without-svg
.endif

.if defined(WITH_TDS)
LIB_DEPENDS+=	ct.4:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-sybase
PLIST_SUB+=	SYBASE:=""
.else
CONFIGURE_ARGS+=	--without-sybase
PLIST_SUB+=	SYBASE:="@comment "
.endif

.if defined(HAVE_MESA) || defined(WITH_MESA)
USE_GL=		yes
LIB_DEPENDS+=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
CONFIGURE_ARGS+=	--with-GL --with-GLUT
.else
CONFIGURE_ARGS+=	--without-GL --without-GLUT
.endif

INSTALL_TARGET=	install_nodoc

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's| -lgmp| -L${LOCALBASE}/lib -lgmp|' \
		${WRKSRC}/src/modules/Gmp/configure ${WRKSRC}/src/modules/_Image_XFace/configure
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|' \
		${WRKSRC}/src/configure
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		${WRKSRC}/src/configure

post-install:
	${STRIP_CMD} ${PREFIX}/pike/${PORTVERSION}/bin/pike
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hilfe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/pike.1 ${MAN1PREFIX}/man/man1

verify:
	@(cd ${WRKSRC}; make verify)

# Autodocs is currently b0rken.... :/
#doc:
#	@(cd ${WRKSRC}; make documentation)

.include <bsd.port.post.mk>
