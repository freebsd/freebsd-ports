# New ports collection makefile for:    virtuoso
# Date created:         		Jul 08, 2006
# Whom:                 		Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	virtuoso
PORTVERSION=	5.0.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-opensource-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Universal SQL/Application Server

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-readline\
		--with-iodbc=${LOCALBASE}\
		--enable-bpel-vad\
		--disable-jdbc
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}"\
		LDFLAGS="-L${LOCALBASE}/lib"
BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS=	iodbc.3:${PORTSDIR}/databases/libiodbc

OPTIONS=	IMAGEMAGICK "ImageMagick support" off\
		KERBEROS "Kerberos extension" off\
		OPENLDAP "OpenLDAP support" off
#		JDBC "JDBC driver" off
#		PERL "Perl hosting" off
#		PYTHON "Python hosting" off
#		MONO "Mono extension" off\
#		PHP4 "PHP4 extension" off\
#		PHP5 "PHP5 extension" off\
#		RUBY "Ruby hosting" off\

post-patch:
	${REINPLACE_CMD}\
		-e 's,-lpthreads,${PTHREAD_LIBS},g'\
		-e 's,-lruby,-lruby${RUBY_VER:S,.,,},g'\
			${WRKSRC}/configure
	${FIND} ${WRKSRC} -name '*.sh' | ${XARGS} ${GREP} -l 'netstat -an.*grep LISTEN' |\
	    ${XARGS} ${REINPLACE_CMD}\
	        -e 's,netstat -an.*grep.*$$\([a-zA-Z0-9]*\).*grep LISTEN,${CHECK_PORT},'

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	${CHMOD} +w ${PREFIX}/virtuoso/demo/demo.db

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		requires wchar_t
.endif

.if ${OSVERSION} < 504000
CHECK_PORT=	${LOCALBASE}/bin/nc -vz localhost $$\1 2>\&1 | ${GREP} open
BUILD_DEPENDS+=	${NETCAT}:${PORTSDIR}/net/netcat
.else
CHECK_PORT=	/usr/bin/nc -z localhost $$\1
.endif

.if defined(WITH_IMAGEMAGICK)
CONFIGURE_ARGS+=--enable-imagemagick=${LOCALBASE}
LIB_DEPENDS+=	Magick.10:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	WITH_IMAGEMAGICK=""
.else
PLIST_SUB+=	WITH_IMAGEMAGICK="@comment "
.endif

#.if defined(WITH_JDBC)
#USE_JAVA=	yes
#JAVA_VERSION=	1.4+
#JAVA_BUILD=	yes
#.endif

.if defined(WITH_KERBEROS)
CONFIGURE_ARGS+=--enable-krb=${LOCALBASE}
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
.endif

# XXX broken (does not build, requires gc.h)
#.if defined(WITH_MONO)
#CONFIGURE_ARGS+=--enable-mono
#.endif

.if defined(WITH_OPENLDAP)
CONFIGURE_ARGS+=--enable-openldap=${LOCALBASE}
USE_OPENLDAP=	yes
.endif

# XXX broken (requires perl to be built with -Dusemultiplicity)
#.if defined(WITH_PERL)
#CONFIGURE_ARGS+=--enable-perl
#USE_PERL5=	yes
#.endif

# XXX broken (no libphp)
#.if defined(WITH_PHP4)
#CONFIGURE_ARGS+=--enable-php4
#.endif

# XXX broken (no libphp)
#.if defined(WITH_PHP5)
#CONFIGURE_ARGS+=--enable-php5
#.endif

# XXX broken (USE_PYTHON does not work with OPTIONS)
#.if defined(WITH_PYTHON)
#CONFIGURE_ARGS+=--enable-python
#USE_PYTHON=	yes
#.endif

# XXX broken (USE_LIBRUBY does not work with OPTIONS)
#.if defined(WITH_RUBY)
#CONFIGURE_ARGS+=--enable-ruby
#USE_LIBRUBY=	yes
#.endif

.include <bsd.port.post.mk>
