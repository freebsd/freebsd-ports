# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtuoso
PORTVERSION=	6.1.6
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-opensource-${PORTVERSION}

MAINTAINER=	michelle@sorbs.net
COMMENT=	Universal SQL/Application Server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk\
		htmldoc:${PORTSDIR}/textproc/htmldoc\
		flex>2.5.4:${PORTSDIR}/textproc/flex\
		gperf>=3.0.3:${PORTSDIR}/devel/gperf\
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

USES=		gmake libtool readline uidfix
USE_AUTOTOOLS=	autoheader aclocal

GNU_CONFIGURE=	yes
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
SUB_FILES=	pkg-message

CHECK_PORT=	nc -z localhost $$\1 2>\&1

OPTIONS_DEFINE=		IMAGEMAGICK KERBEROS LDAP IODBC

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
	${FIND} ${STAGEDIR} -name "*.ini" -exec ${MV} {} {}.sample \; -print

check:
	${SETENV} -u HOST ${MAKE_ENV} ${MAKE} -C ${WRKSRC} check

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
CONFIGURE_ARGS+=--enable-imagemagick=${LOCALBASE}
LIB_DEPENDS+=	libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	WITH_IMAGEMAGICK=""
.else
CONFIGURE_ARGS+=--disable-imagemagick
PLIST_SUB+=	WITH_IMAGEMAGICK="@comment "
.endif

.if ${PORT_OPTIONS:MIODBC}
CONFIGURE_ARGS+=--with-iodbc=${LOCALBASE}
LIB_DEPENDS+=	libiodbc.so:${PORTSDIR}/databases/libiodbc
IODBC_CPPFLAGS=
PLIST_SUB+=	WITH_IODBC=""
.else
IODBC_CPPFLAGS=	-I../../libsrc/odbcsdk/include
PLIST_SUB+=	WITH_IODBC="@comment "
.endif

.if ${PORT_OPTIONS:MKERBEROS}
CONFIGURE_ARGS+=--enable-krb=${LOCALBASE}
LIB_DEPENDS+=	libkrb5.so:${PORTSDIR}/security/krb5
.else
CONFIGURE_ARGS+=--disable-krb
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=--enable-openldap=${LOCALBASE}
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-openldap
.endif

.include <bsd.port.mk>
