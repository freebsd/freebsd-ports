# $FreeBSD$

PORTNAME=	pike78
PORTVERSION=	7.8.700
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://pike.ida.liu.se/pub/pike/all/${PORTVERSION}/ \
		ftp://pike.ida.liu.se/pub/pike/beta/${PORTVERSION}/ \
		http://pike.ida.liu.se/pub/pike/beta/${PORTVERSION}/ \
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

CONFLICTS=	pike7[26]-[0-9]*

OPTIONS_DEFINE=	TTF FREETYPE MYSQL PGSQL
OPTIONS_DEFAULT=TTF FREETYPE MYSQL
NO_OPTIONS_SORT=yes
TTF_DESC?=	Enable FreeType 1 (libttf) font rendering engine

MAN1=		pike.1

CFLAGS+=	-ffast-math -fomit-frame-pointer

CONFIGURE_ENV=	CPPFLAGS+=${PTHREAD_CFLAGS} M4="/usr/bin/m4 -g"
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
		 --with-relocatable-dumped-modules \
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
MAKE_ENV=	"ac_cv_lib_nettle_nettle_md5_init=no"

USES=		bison gettext gmake perl5

# Allow building Embedded Perl
CONFIGURE_ARGS+=	--with-perl

PLIST_FILES=	bin/pike bin/pike78 bin/hilfe

NO_STAGE=	yes
.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

.if ${OSVERSION} < 800000
BROKEN=		Does not build on FreeBSD < 8.x
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
	@cd ${PREFIX} && ${FIND} pike/${PORTVERSION} ! -type d >> ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} pike/${PORTVERSION} -type d -empty -delete
	@cd ${PREFIX} && ${FIND} -d pike/${PORTVERSION} -type d | \
		${SED} 's,^,@dirrm ,' >> ${TMPPLIST}
	@${ECHO} '@unexec rmdir %D/pike 2>/dev/null || true' >> ${TMPPLIST}

verify:
	@(cd ${WRKSRC}; make verify)

.include <bsd.port.post.mk>
