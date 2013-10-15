# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtuoso
PORTVERSION=	6.1.6
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-opensource-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Universal SQL/Application Server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk\
		htmldoc:${PORTSDIR}/textproc/htmldoc\
		flex>2.5.4:${PORTSDIR}/textproc/flex\
		gperf>=3.0.3:${PORTSDIR}/devel/gperf\
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

.if defined(.PARSEDIR)
USE_GMAKE=	yes
.endif

USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-readline\
		--without-jdk2\
		--without-jdk3\
		--without-jdk4\
		--disable-hslookup\
		--disable-wbxml2\
		--enable-bpel-vad\
		--with-layout=freebsd\
		--datadir="${PREFIX}"\
		--localstatedir="${PREFIX}"
CPPFLAGS+=	-std=gnu89 ${IODBC_CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	PATH=${LOCALBASE}/bin:${PATH}\
		ISQL=isql-vt
USE_RC_SUBR=	virtuoso
USERS=		virtuoso
GROUPS=		virtuoso

CHECK_PORT=	/usr/bin/nc -z localhost $$\1 2>\&1

OPTIONS_DEFINE=		IMAGEMAGICK KERBEROS LDAP IODBC
#OPTIONS_DEFINE+=		MONO PERL PHP4 PHP5 PYTHON RUBY

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD}\
		-e 's,-lpthreads,${PTHREAD_LIBS},g'\
		-e 's,-lruby,-lruby${RUBY_VER:S,.,,},g'\
			${WRKSRC}/configure
	${FIND} ${WRKSRC} -name '*.sh' | ${XARGS} ${GREP} -l 'netstat -an.*grep LISTEN' |\
	    ${XARGS} ${REINPLACE_CMD}\
		-e 's,expr \$$,expr -- $$,'\
		-e 's,netstat -an.*grep.*$$\([a-zA-Z0-9]*\).*grep LISTEN,${CHECK_PORT},'

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

check:
	${SETENV} -u HOST ${MAKE_ENV} ${MAKE} -C ${WRKSRC} check

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
CONFIGURE_ARGS+=--enable-imagemagick=${LOCALBASE}
LIB_DEPENDS+=	MagickWand:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	WITH_IMAGEMAGICK=""
.else
CONFIGURE_ARGS+=--disable-imagemagick
PLIST_SUB+=	WITH_IMAGEMAGICK="@comment "
.endif

.if ${PORT_OPTIONS:MIODBC}
CONFIGURE_ARGS+=--with-iodbc=${LOCALBASE}
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
IODBC_CPPFLAGS=
PLIST_SUB+=	WITH_IODBC=""
.else
IODBC_CPPFLAGS=	-I../../libsrc/odbcsdk/include
PLIST_SUB+=	WITH_IODBC="@comment "
.endif

.if ${PORT_OPTIONS:MKERBEROS}
CONFIGURE_ARGS+=--enable-krb=${LOCALBASE}
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
.else
CONFIGURE_ARGS+=--disable-krb
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=--enable-openldap=${LOCALBASE}
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-openldap
.endif

# XXX broken (does not build, requires gc.h)
#.if ${PORT_OPTIONS:MMONO}
#CONFIGURE_ARGS+=--enable-mono
#.endif

# XXX broken (requires perl to be built with -Dusemultiplicity)
#.if ${PORT_OPTIONS:MPERL}
#CONFIGURE_ARGS+=--enable-perl
#USE_PERL5=	yes
#.endif

# XXX broken (no libphp)
#.if ${PORT_OPTIONS:MPHP4}
#CONFIGURE_ARGS+=--enable-php4
#.endif

# XXX broken (no libphp)
#.if ${PORT_OPTIONS:MPHP5}
#CONFIGURE_ARGS+=--enable-php5
#.endif

# XXX broken (USE_PYTHON does not work with OPTIONS)
#.if ${PORT_OPTIONS:MPYTHON}
#CONFIGURE_ARGS+=--enable-python
#USE_PYTHON=	yes
#.endif

# XXX broken (USE_LIBRUBY does not work with OPTIONS)
#.if ${PORT_OPTIONS:MRUBY}
#CONFIGURE_ARGS+=--enable-ruby
#USE_LIBRUBY=	yes
#.endif

.include <bsd.port.mk>
