# Created by: kiwi@oav.net
# $FreeBSD$

PORTNAME=	pike76
PORTVERSION=	7.6.112
PORTREVISION=	18
CATEGORIES=	lang
MASTER_SITES=	ftp://pike.ida.liu.se/pub/pike/beta/${PORTVERSION}/ \
		http://pike.ida.liu.se/pub/pike/beta/${PORTVERSION}/ \
		ftp://pike.ida.liu.se/pub/pike/all/${PORTVERSION}/ \
		http://pike.ida.liu.se/pub/pike/all/${PORTVERSION}/ \
		ftp://ftp.oav.net/pike/7.6/ \
		ftp://ftp.caudium.net/pike/official_releases/${PORTVERSION}/
DISTNAME=	Pike-v${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A dynamic programming language with a syntax similar to C++

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		gdbm:${PORTSDIR}/databases/gdbm \
		pcre:${PORTSDIR}/devel/pcre \
		mird:${PORTSDIR}/databases/mird \
		gmp:${PORTSDIR}/math/gmp

CONFLICTS=	pike7[28]-[0-9]*
CONFLICTS_BUILD=nettle-[2-9]*

OPTIONS_DEFINE=	TTF FREETYPE OPT_CFLAGS MYSQL FFMPEG PGSQL \
		SANE PDF SVG2 TDS FFTW
OPTIONS_DEFAULT=TTF FREETYPE OPT_CFLAGS MYSQL NOODBC
OPTIONS_SINGLE=	ODBC
OPTIONS_SINGLE_ODBC=	NOODBC UNIXODBC IODBC

TTF_DESC?=	Add FreeType 1 support
FREETYPE_DESC?=	Add FreeType 2 support
OPT_CFLAGS_DESC?=	Enable additional compiliation optimizations
FFMPEG_DESC?=	Add FFmpeg support
NOODBC_DESC?=	No ODBC support (default)
UNIXODBC_DESC?=	Add UnixODBC support
IODBC_DESC?=	Add iODBC support
SANE_DESC?=	Add SANE support
PDF_DESC?=	Add PDF support
SVG2_DESC?=	Add SVG2 support
TDS_DESC?=	Add FreeTDS (Sybase and MSSQL) support
FFTW_DESC?=	Add libFFTW support

MAN1=		pike.1

WANT_MESA=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
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
		 --with-relocatable-dumped-modules \
		 --without-GL --without-GLUT \
		 --prefix=${PREFIX}

MAKE_ARGS=	CONFIGUREARGS="${CONFIGURE_ARGS}"

USES=		bison gettext gmake perl

# Allow building Embedded Perl
CONFIGURE_ARGS+=	--with-perl

PLIST_FILES=	bin/pike bin/pike76 bin/hilfe

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

.if ${OSVERSION} < 800000 && ${ARCH} == "amd64"
BROKEN=		segfaults during build
.endif

.if ${PORT_OPTIONS:MEXPERIMENTAL_FEATURES}
CONFIGURE_ARGS+=	--with-computed-goto \
		--with-pg \
		--with-long-long-int \
		--with-long-int \
		--with-short-int \
		--with-keypair-loop \
		--without-lock \
		--with-new-multisets
.endif

.if ${PORT_OPTIONS:MOPT_CFLAGS}
.if (${MACHINE} == "i386")
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.else
CFLAGS+=	-ffast-math -fomit-frame-pointer
.endif
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--with-ffmpeg
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if ${PORT_OPTIONS:MFFTW}
LIB_DEPENDS+=	fftw:${PORTSDIR}/math/fftw
.endif

.if ${PORT_OPTIONS:MTTF}
LIB_DEPENDS+=	ttf:${PORTSDIR}/print/freetype
CONFIGURE_ARGS+=	--with-ttflib
.else
CONFIGURE_ARGS+=	--without-ttflib
.endif

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-freetype
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if ${PORT_OPTIONS:MMSQL}
BUILD_DEPENDS+=	msql:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-msql
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc
.endif

.if ${PORT_OPTIONS:MIODBC}
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-odbc
.endif

.if ${PORT_OPTIONS:MNOODBC}
CONFIGURE_ARGS+=	--without-odbc
.endif

.if ${PORT_OPTIONS:MSANE}
LIB_DEPENDS+=	sane:${PORTSDIR}/graphics/sane-backends
CONFIGURE_ARGS+=	--with-sane
.else
CONFIGURE_ARGS+=	--without-sane
.endif

.if ${PORT_OPTIONS:MPDF}
LIB_DEPENDS+=	pdf:${PORTSDIR}/print/pdflib \
		panda:${PORTSDIR}/print/panda
CONFIGURE_ARGS+=	--with-libpdf --with-libpanda
.else
CONFIGURE_ARGS+=	--without-libpdf --without-libpanda
.endif

.if ${PORT_OPTIONS:MSVG2}
LIB_DEPENDS+=	rsvg-2:${PORTSDIR}/graphics/librsvg2
CONFIGURE_ARGS+=	--with-svg
.else
CONFIGURE_ARGS+=	--without-svg
.endif

.if ${PORT_OPTIONS:MTDS}
LIB_DEPENDS+=	ct:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+=	--with-sybase
PLIST_SUB+=	SYBASE:=""
.else
CONFIGURE_ARGS+=	--without-sybase
PLIST_SUB+=	SYBASE:="@comment "
.endif

INSTALL_TARGET=	install_nodoc

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's| -lgmp| -L${LOCALBASE}/lib -lgmp|' \
		${WRKSRC}/src/modules/Gmp/configure ${WRKSRC}/src/modules/_Image_XFace/configure
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|' \
			-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
			-e "s|/cc/|&'|" \
		${WRKSRC}/src/configure

post-install:
	@${STRIP_CMD} ${PREFIX}/pike/${PORTVERSION}/bin/pike
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/hilfe ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/pike.1 ${MAN1PREFIX}/man/man1
	@cd ${PREFIX} && ${FIND} pike/${PORTVERSION} ! -type d >> ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} pike/${PORTVERSION} -type d -empty -delete
	@cd ${PREFIX} && ${FIND} -d pike/${PORTVERSION} -type d | \
		${SED} 's,^,@dirrm ,' >> ${TMPPLIST}
	@${ECHO} '@unexec rmdir %D/pike 2>/dev/null || true' >> ${TMPPLIST}

.include <bsd.port.post.mk>
