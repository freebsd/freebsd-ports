# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION}	# get these from bsd.thrift.mk. any upgrade needs to check ALL dependencies
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	/thrift/${PORTVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	Framework for scalable cross-language services development

LICENSE=	AL2

LIB_DEPENDS=	boost_iostreams:${PORTSDIR}/devel/boost-libs \
		event-1.4:${PORTSDIR}/devel/libevent

USE_AUTOTOOLS=	autoconf autoheader:env aclocal automake libtool
ACLOCAL_ARGS=	-I${WRKSRC}/aclocal
AUTOMAKE_ARGS=	--foreign --add-missing --copy

USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS=	--with-boost=${LOCALBASE} --with-libevent=${LOCALBASE} \
		--enable-shared --enable-static --with-zlib
CONFIGURE_ENV+=	${MAKE_ENV}

OPTIONS_DEFINE=	GLIB QT4
GLIB_DESC=	C (GLib) Library

# For Perl support, use devel/p5-Thrift.
# For Python support, use devel/py-thrift.
# For Ruby support, use devel/rubygem-thrift.
# For PHP support, use devel/php5-thrift.
# Other languages are not yet supported, please feel free to contribute
# using one of the leaf ports as an example.
CONFIGURE_ARGS+=	\
		--with-cpp \
		--without-csharp \
		--without-erlang \
		--without-haskell \
		--without-java \
		--without-perl \
		--without-php \
		--without-php_extension \
		--without-python \
		--without-ruby

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>
.include "bsd.thrift.mk"

.if ${PORT_OPTIONS:MGLIB}
    CONFIGURE_ARGS+=	--with-c_glib
    LIB_DEPENDS+=	glib-2.0:${PORTSDIR}/devel/glib20
    PLIST_SUB+=		GLIB=""
    WITH_GLIB=		true
.else
    CONFIGURE_ARGS+=	--without-c_glib
    PLIST_SUB+=		GLIB="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
    CONFIGURE_ARGS+=	--with-qt4
    USE_QT4=		network moc_build qmake_build rcc_build uic_build
    PLIST_SUB+=		QT=""
    WITH_QT=		true
.else
    CONFIGURE_ARGS+=	--without-qt4
    PLIST_SUB+=		QT="@comment "
.endif

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} 's,^pkgconfigdir = .*,pkgconfigdir=$${prefix}/libdata/pkgconfig,' ${WRKSRC}/lib/cpp/Makefile.am
	@${REINPLACE_CMD} 's,^pkgconfigdir = .*,pkgconfigdir=$${prefix}/libdata/pkgconfig,' ${WRKSRC}/lib/c_glib/Makefile.am

pre-configure:
	@${REINPLACE_CMD} '/config.h/d' ${WRKSRC}/lib/cpp/Makefile.am

post-install:
	@${LN} -sf ${PREFIX}/lib/libthrift-${PORTVERSION}.so ${PREFIX}/lib/libthrift.so.0
	@${LN} -sf ${PREFIX}/lib/libthriftnb-${PORTVERSION}.so ${PREFIX}/lib/libthriftnb.so.0
	@${LN} -sf ${PREFIX}/lib/libthriftz-${PORTVERSION}.so ${PREFIX}/lib/libthriftz.so.0
	@${ECHO_MSG}
	@${ECHO_MSG} "For use with C++, the same compiler as used to build this port must be used"
	@${ECHO_MSG} "to compile and link your generated IDL bindings."
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: The Thrift white paper may be downloaded from:"
	@${ECHO_MSG} "http://thrift.apache.org/static/thrift-20070401.pdf"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
