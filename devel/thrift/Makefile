# New ports collection makefile for:	thrift
# Date created:	   27 September 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	0.6.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	/thrift/${PORTVERSION}
DISTNAME=	thrift-${PORTVERSION}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Framework for scalable cross-language services development

LICENSE=	ASL

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

# For Perl support, use devel/p5-Thrift.
# For Python support, use devel/py-thrift.
# For Ruby support, use devel/ruby-thrift.
# Other languages are not yet supported, please feel free to contribute
# using one of the leaf ports as an example.
CONFIGURE_ARGS+=	\
		--with-cpp \
		--without-c_glib \
		--without-csharp \
		--without-erlang \
		--without-haskell \
		--without-java \
		--without-perl \
		--without-php \
		--without-php_extension \
		--without-python \
		--without-ruby

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} 's,^pkgconfigdir = .*,pkgconfigdir=$${prefix}/libdata/pkgconfig,' ${WRKSRC}/lib/cpp/Makefile.am

pre-configure:
	@${REINPLACE_CMD} '/config.h/d' ${WRKSRC}/lib/cpp/Makefile.am

post-install:
	@${LN} -sf ${PREFIX}/lib/libthrift.so.0 ${PREFIX}/lib/libthrift.so
	@${LN} -sf ${PREFIX}/lib/libthriftnb.so.0 ${PREFIX}/lib/libthriftnb.so
	@${LN} -sf ${PREFIX}/lib/libthriftz.so.0 ${PREFIX}/lib/libthriftz.so
	@${ECHO_MSG}
	@${ECHO_MSG} "For use with C++, the same compiler as used to build this port must be used"
	@${ECHO_MSG} "to compile and link your generated IDL bindings."
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: The Thrift white paper may be downloaded from:"
	@${ECHO_MSG} "http://thrift.apache.org/static/thrift-20070401.pdf"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
