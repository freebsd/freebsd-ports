# New ports collection makefile for:	pike74
# Date created:		24 Jun 2003
# Whom:			kiwi@oav.net
#
# $FreeBSD$
#

PORTNAME=	pike74
PORTVERSION=	7.4.31
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://pike.ida.liu.se/pub/pike/all/${PORTVERSION}/ \
		ftp://ftp.oav.net/pkg_freebsd/distfiles/ \
		http://ftp.oav.net/pkg_freebsd/distfiles/ \
		ftp://ftp.oav.net/pike/7.4/export/ \
		http://ftp.oav.net/pike/7.4/export/ \
		http://grendel.firewall.com/caudium-pkg/ \
		ftp://ftp.caudium.net/pike/official_releases/${PORTVERSION}/
DISTNAME=	Pike-v${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	A dynamic programming language with a syntax similar to C++

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison/
.if (${MACHINE} == "i386")
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm/
.endif
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		fftw.2:${PORTSDIR}/math/fftw

MAN1=		pike.1

WRKSRC=		${WRKDIR}/${DISTNAME}/src/

WANT_MESA=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--without-debug \
		 --with-double-precision \
		 --with-long-double-precision \
		 --disable-rpath \
		 --without-rtldebug \
		 --without-cdebug \
		 --without-copt \
		 --without-security \
		 --with-oob \
		 --with-poll \
		 --with-max-fd=60000 \
		 --with-gmp \
		 --with-zlib \
		 --with-threads \
		 --with-readline \
		 --with-jpeg=${PREFIX} \
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

USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

# FreeBSD 5.0 Needs to have libgmp port to support gmp.
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	gmp.6:${PORTSDIR}/math/libgmp4
.endif

# Allow building Embeded perl when >= 5.6
.if ${PERL_LEVEL} > 500600
CONFIGURE_ARGS+=	--with-perl
USE_PERL5=	YES
.else
CONFIGURE_ARGS+=	--without-perl
.endif

.if exists(${LOCALBASE}/lib/libavcodec.so.0)
WITH_FFMPEG=	yes
.endif

.if exists(${LOCALBASE}/lib/libttf.so.4)
WITH_TTF=	yes
.endif

.if exists(${LOCALBASE}/lib/libfreetype.so.9)
WITH_FREETYPE=	yes
.endif

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.10)
WITH_MYSQL=	yes
.endif

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.12)
WITH_MYSQL40=	yes
.endif

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.14)
WITH_MYSQL41=	yes
.endif

.if exists(${LOCALBASE}/lib/libpq.so.3)
WITH_POSTGRES=	yes
.endif

.if exists(${LOCALBASE}/lib/libodbc.so.1)
WITH_UNIXODBC=	yes
.endif

.if exists(${LOCALBASE}/lib/libiodbc.so.2)
WITH_IODBC=	yes
.endif

.if exists(${LOCALBASE}/lib/libsane.so.1)
WITH_SANE=	yes
.endif

.if exists(${LOCALBASE}/lib/libgtkgl.so.5)
WITH_MESA=	yes
.endif

.if exists(${LOCALBASE}/lib/libpdf.so.6) || exists(${LOCALBASE}/lib/libpanda.so.0)
WITH_PDF=	yes
.endif

.if exists(${LOCALBASE}/lib/librsvg-2.so.2)
WITH_SVG2=	yes
.endif

.if exists(${LOCALBASE}/lib/libct.so.1)
WITH_TDS=	yes
.endif

.if defined(WITH_MOST)
WITH_TTF=	yes
WITH_FREETYPE=	yes
.endif

.if defined(WITHOUT_RELOCATABLE_DUMPED_MODULES)
CONFIGURE_ARGS+=	--without-relocatable-dumped-modules
.else
CONFIGURE_ARGS+=	--with-relocatable-dumped-modules
.endif

.if defined(WITH_EXPIREMENTAL_FEATURES)
CONFIGURE_ARGS+= --with-computed-goto \
		 --with-pg \
		 --with-long-long-int \
		 --with-long-int \
		 --with-short-int \
		 --with-keypair-loop \
		 --without-lock \
		 --with-new-multisets
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
.if (${MACHINE} == "i386")
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.else
CFLAGS+=	-ffast-math -fomit-frame-pointer
.endif
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.0:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+= --with-ffmpeg
.else
CONFIGURE_ARGS+= --without-ffmpeg
.endif

.if defined(WITH_TTF)
LIB_DEPENDS+=	ttf.4:${PORTSDIR}/print/freetype
CONFIGURE_ARGS+= --with-ttflib
.else
CONFIGURE_ARGS+= --without-ttflib
.endif

.if defined(WITH_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+= --with-freetype
.else
CONFIGURE_ARGS+= --without-freetype
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+= --with-mysql=${PREFIX}
.else
CONFIGURE_ARGS+= --without-mysql
.endif

.if defined(WITH_MYSQL40)
LIB_DEPENDS+=	mysqlclient.12:${PORTSDIR}/databases/mysql40-client
CONFIGURE_ARGS+= --with-mysql=${PREFIX}
.else
CONFIGURE_ARGS+= --without-mysql
.endif

.if defined(WITH_MYSQL41)
LIB_DEPENDS+=	mysqlclient.14:${PORTSDIR}/databases/mysql41-client
CONFIGURE_ARGS+= --with-mysql=${PREFIX}
.else
CONFIGURE_ARGS+= --without-mysql
.endif

.if defined(WITH_POSTGRES)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+= --with-pgsql=${PREFIX}
.else
CONFIGURE_ARGS+= --without-pgsql
.endif

.if defined(WITH_MSQL)
BUILD_DEPENDS+=	msql:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+= --with-msql=${PREFIX}
.else
CONFIGURE_ARGS+= --without-msql
.endif

.if defined(WITH_UNIXODBC)
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+= --with-odbc
.endif

.if defined(WITH_IODBC)
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+= --with-odbc
.endif

.if !defined(WITH_UNIXODBC) && !defined(WITH_IODBC)
CONFIGURE_ARGS+= --without-odbc
.endif

.if defined(WITH_SANE)
LIB_DEPENDS+=	sane.1:${PORTSDIR}/graphics/sane-backends
CONFIGURE_ARGS+= --with-sane
.else
CONFIGURE_ARGS+= --without-sane
.endif

.if defined(WITH_PDF)
LIB_DEPENDS+=	pdf.6:${PORTSDIR}/print/pdflib \
		panda.0:${PORTSDIR}/print/panda
CONFIGURE_ARGS+= --with-libpdf --with-libpanda
.else
CONFIGURE_ARGS+= --without-libpdf --without-libpanda
.endif

.if defined(WITH_SVG2)
LIB_DEPENDS+=	librsvg-2.2:${PORTSDIR}/graphics/librsvg2
CONFIGURE_ARGS+= --with-svg
.else
CONFIGURE_ARGS+= --without-svg
.endif

.if defined(WITH_TDS)
LIB_DEPENDS+=	ct.1:${PORTSDIR}/databases/freetds
CONFIGURE_ARGS+= --with-sybase
PLIST_SUB+=	SYBASE:=""
.else
CONFIGURE_ARGS+= --without-sybase
PLIST_SUB+=	SYBASE:="@comment "
.endif

.if defined(HAVE_MESA) || defined(WITH_MESA)
USE_MESA=	yes
LIB_DEPENDS+=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
CONFIGURE_ARGS+= --with-GL --with-GLUT
.else
CONFIGURE_ARGS+= --without-GL --without-GLUT
.endif

#.if (${MACHINE} == "i386")
#CONFIGURE_ARGS+= --with-poll
#.else
## Alpha seems to have problems with poll() with pike... :/
#CONFIGURE_ARGS+= --without-poll
#.endif

USE_GMAKE=	yes

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif
.if !defined(WITH_FFMPEG)
	@${ECHO_MSG} "You can enable FFmpeg support by defining WITH_FFMPEG."
.endif
.if !defined(WITH_TTF) && !defined(WITH_MOST)
	@${ECHO_MSG} "You can enable _Image_TTF support by defining WITH_TTF."
.endif
.if !defined(WITH_FREETYPE) && !defined(WITH_MOST)
	@${ECHO_MSG} "You can enable _Image_FreeType support by defining WITH_FREETYPE."
.endif
.if !defined(WITH_MYSQL)
	@${ECHO_MSG} "You can enable MySQL 3.23 support by defining WITH_MYSQL."
.endif
.if !defined(WITH_MYSQL40)
	@${ECHO_MSG} "You can enable MySQL 4.0 support by defining WITH_MYSQL40."
.endif
.if !defined(WITH_MYSQL41)
	@${ECHO_MSG} "You can enable MySQL 4.1 support by defining WITH_MYSQL41."
.endif
.if !defined(WITH_POSTGRES)
	@${ECHO_MSG} "You can enable PostGres support by defining WITH_POSTGRES."
.endif
.if !defined(WITH_UNIXODBC) && !defined(WITH_IODBC)
	@${ECHO_MSG} "You can enable unixODBC support by defining WITH_UNIXODBC."
	@${ECHO_MSG} "You can enable iodbc support by defining WITH_IODBC."
	@${ECHO_MSG} "Note that you can support only ONE of these two ODBC libs."
.endif
.if !defined(WITH_SANE)
	@${ECHO_MSG} "You can enable Sane support by defining WITH_SANE."
.endif
.if !defined(WITH_SANE) || !defined(HAVE_MESA)
	@${ECHO_MSG} "You can enable MesaGL support by defining WITH_MESA."
.endif
.if !defined(WITH_PDF)
	@${ECHO_MSG} "You can enable PDF support by defining WITH_PDF."
.endif
.if !defined(WITH_MOST)
	@${ECHO_MSG} "You can enable most of the features here except Sane,"
	@${ECHO_MSG} "MesaGLi and SQL support by defining WITH_MOST."
.endif
.if !defined(WITH_SVG2)
	@${ECHO_MSG} "You can enable SVG2 image support by "
	@${ECHO_MSG} "defining WITH_SVG2."
.endif
.if !defined(WITHOUT_RELOCATABLE_DUMPED_MODULES)
	@${ECHO_MSG} "You can disable relocatable dumped modules by "
	@${ECHO_MSG} "defining WITHOUT_RELOCATABLE_DUMPED_MODULES."
.endif
.if !defined(WITH_EXPIREMENTAL_FEATURES)
	@${ECHO_MSG} "You can enable experemental features and optimization "
	@${ECHO_MSG} "at you own risk by defining WITH_EXPIREMENTAL_FEATURES."
.endif
.if !defined(WITH_TDS)
	@${ECHO_MSG} "You can enable direct access to Sybase and MS-SQL "
	@${ECHO_MSG} "database using FreeTDS be defining WITH_TDS."
.endif

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's| -lgmp| -L${LOCALBASE}/lib -lgmp|' \
		${WRKSRC}/modules/Gmp/configure ${WRKSRC}/modules/_Image_XFace/configure

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}pike ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}hilfe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}../man/pike.1 ${MAN1PREFIX}/man/man1

verify:
	@(cd ${WRKSRC}; make verify)

# Autodocs is currently b0rken.... :/
#doc:
#	@(cd ${WRKSRC}; make documentation)

.include <bsd.port.post.mk>
