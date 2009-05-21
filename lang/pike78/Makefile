# New ports collection makefile for:	pike78
# Date created:		17 May 2009
# Whom:			johans@stack.nl
#
# $FreeBSD$
#

PORTNAME=	pike78
PORTVERSION=	7.8.116
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://pike.ida.liu.se/pub/pike/all/${PORTVERSION}/ \
		http://pike.ida.liu.se/pub/pike/all/${PORTVERSION}/ \
		ftp://pike.ida.liu.se/pub/pike/beta/${PORTVERSION}/ \
		http://pike.ida.liu.se/pub/pike/beta/${PORTVERSION}/ \
		ftp://ftp.caudium.net/pike/official_releases/${PORTVERSION}/
DISTNAME=	Pike-v${PORTVERSION}

MAINTAINER=	johans@stack.nl
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
		MYSQL "Add MySQL support" on \
		POSTGRESQL "Add Postgres SQL support" off

MAN1=		pike.1

CFLAGS+=	-ffast-math -fomit-frame-pointer

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
		 --without-GL --without-GLUT \
		 --without-GTK \
		 --without-ffmpeg \
		 --without-fftw \
		 --without-glade \
		 --without-gnome \
		 --without-gssapi \
		 --without-java \
		 --without-libglade-config \
		 --without-libpdf --without-libpanda \
		 --without-machine-code \
		 --without-msql \
		 --without-odbc \
		 --without-sane \
		 --without-svg \
		 --without-sybase \
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

.ifdef(WITHOUT_RELOCATABLE_DUMPED_MODULES)
CONFIGURE_ARGS+=	--without-relocatable-dumped-modules
.else
CONFIGURE_ARGS+=	--with-relocatable-dumped-modules
.endif

.ifdef(WITH_TTF)
LIB_DEPENDS+=	ttf.4:${PORTSDIR}/print/freetype
CONFIGURE_ARGS+=	--with-ttflib
.else
CONFIGURE_ARGS+=	--without-ttflib
.endif

.ifdef(WITH_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--with-freetype
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

.ifdef(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.ifdef(WITH_POSTGRESQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's| -lgmp| -L${LOCALBASE}/lib -lgmp|' \
		${WRKSRC}/src/modules/Gmp/configure ${WRKSRC}/src/modules/_Image_XFace/configure
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|' \
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		-e 's|,-Bshareable|& -shared|' \
		${WRKSRC}/src/configure
	@${REINPLACE_CMD} -e '/install.*MANDIR/s|^|//|' \
		${WRKSRC}/bin/install.pike

post-install:
	${STRIP_CMD} ${PREFIX}/pike/${PORTVERSION}/bin/pike
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hilfe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/pike.1 ${MAN1PREFIX}/man/man1

verify:
	@(cd ${WRKSRC}; make verify)

.include <bsd.port.post.mk>
