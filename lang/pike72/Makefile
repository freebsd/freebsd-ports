# New ports collection makefile for:    pike
# Date created:         16 Jan 1999
# Whom:                 vns@delta.odessa.ua
#
# $FreeBSD$
#

PORTNAME=	pike72
PORTVERSION=	7.2.570
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.oav.net/pike/7.2/unofficial/ \
		ftp://ftp.us.caudium.net/pub/pike/7.2/unofficial/ 
DISTNAME=	pike-${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	A dynamic programming language with a syntax similar to C++

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		mird.1:${PORTSDIR}/databases/mird

WRKSRC=		${WRKDIR}/${DISTNAME}/src/

USE_BISON=	yes
USE_GETTEXT=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+= --without-debug \
		 --disable-rpath \
		 --without-rtldebug \
		 --without-cdebug \
		 --without-copt \
		 --without-shared-nodes \
		 --without-security \
		 --with-oob \
		 --with-poll \
		 --with-max-fd=60000 \
		 --without-relocatable-dumped-modules \
		 --without-libpanda \
		 --without-perl \
		 --without-GTK \
		 --with-gmp \
		 --with-zlib \
		 --with-threads \
		 --with-readline \
		 --with-jpeg=${PREFIX} \
		 --with-tiff \
		 --with-gdbm \
		 --without-ssleay

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" || ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not build on alpha, amd64 or ia64"
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--with-long-double-precision
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

# FreeBSD 5.0 Needs to have libgmp port to support gmp.
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=   gmp.7:${PORTSDIR}/math/libgmp4
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

.if exists(${LOCALBASE}/lib/libpq.so)
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

.if exists(${LOCALBASE}/lib/libpdf.so.7)
WITH_PDF=	yes
.endif

.if defined(WITH_MOST)
WITH_TTF=	yes
WITH_FREETYPE=	yes
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
.if (${MACHINE} == "i386")
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.else
CFLAGS+=	-ffast-math -fomit-frame-pointer
.endif
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

.if defined(WITH_POSTGRES)
USE_PGSQL=	yes
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
LIB_DEPENDS+=	pdf.7:${PORTSDIR}/print/pdflib
CONFIGURE_ARGS+= --with-libpdf
.else
CONFIGURE_ARGS+= --without-libpdf
.endif

USE_GMAKE=	yes
MAN1=		hilfe.1 pike.1
MAN1PREFIX=	${PREFIX}/pike/${PORTVERSION}

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif
.if !defined(WITH_TTF) && !defined(WITH_MOST)
	@${ECHO_MSG} "You can enable _Image_TTF support by defining WITH_TTF."
.endif
.if !defined(WITH_FREETYPE) && !defined(WITH_MOST)
	@${ECHO_MSG} "You can enable _Image_FreeType support by defining WITH_FREETYPE."
.endif
.if !defined(WITH_MYSQL)
	@${ECHO_MSG} "You can enable MySQL support by defining WITH_MYSQL."
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
.if !defined(WITH_PDF)
	@${ECHO_MSG} "You can enable PDF support by defining WITH_PDF."
.endif
.if !defined(WITH_MOST)
	@${ECHO_MSG} "You can enable most of the features here except Sane,"
	@${ECHO_MSG} "MesaGLi, GNOME and SQL support by defining WITH_MOST."
.endif

pre-configure:
#	@cd ${WRKSRC}; \
#	./run_autoconfig
	@${ECHO} ${CONFIGURE_ARGS}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}pike ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}hilfe ${PREFIX}/bin

.include <bsd.port.post.mk>
