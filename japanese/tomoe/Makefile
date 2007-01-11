# New ports collection makefile for:	ja-tomoe
# Date created:				18 Dec 2005
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tomoe
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=tomoe/23340
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Tegaki Online MOji-ninshiki Engine

USE_GNOME=	lthack gnomehack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
USE_RUBY=	yes

BUILD_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/glib2.so:${PORTSDIR}/devel/ruby-glib2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/glib2.so:${PORTSDIR}/devel/ruby-glib2

OPTIONS=DICT_RUBY	"Enable Ruby based dictionary module"		off \
	EST		"Enable Hyper Estraier dictionary module"	off \
	MYSQL		"Enable MySQL dictionary module"		off \
	UNIHAN		"Enable Unihan database dictionary module"	on

.include <bsd.port.pre.mk>

.if defined(WITH_DICT_RUBY)
CONFIGURE_ARGS+=--enable-dict-ruby
PLIST_SUB+=	DICT_RUBY=""
.else
PLIST_SUB+=	DICT_RUBY="@comment "
.endif

.if defined(WITH_EST)
CONFIGURE_ARGS+=--with-est
PLIST_SUB+=	EST=""
.else
PLIST_SUB+=	EST="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_UNIHAN)
MASTER_SITES+=	ftp://ftp.unicode.org/Public/UNIDATA/:unihan
DISTFILES+=	Unihan.zip:unihan
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+=	\
	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv \
	${RUBY_SITELIBDIR}/suikyo/suikyo.rb:${PORTSDIR}/japanese/suikyo
PLIST_SUB+=	UNIHAN=""
.else
CONFIGURE_ARGS+=--disable-unihan
PLIST_SUB+=	UNIHAN="@comment "
.endif

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

.if defined(WITH_UNIHAN)
post-extract:
	cd ${WRKSRC}/module/dict && \
		${UNZIP_CMD} -qo ${DISTDIR}/Unihan.zip -d ${WRKSRC}/module/dict
.endif

.include <bsd.port.post.mk>
