# New ports collection makefile for:	ja-tomoe
# Date created:				18 Dec 2005
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tomoe
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Tegaki Online MOji-ninshiki Engine

USE_GNOME=	lthack gnomehack
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_RUBY=	yes
USE_PERL5_BUILD=yes

BUILD_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/glib2.so:${PORTSDIR}/devel/ruby-glib2 \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/glib2.so:${PORTSDIR}/devel/ruby-glib2

# We cannot use ${ARCH} nor ${UNAME} which are defined in bsd.port.mk, here.
UNAME?=		/usr/bin/uname
ARCH!=		${UNAME} -p
.if !defined(OSVERSION)
AWK?=		/usr/bin/awk
SYSCTL?=	/sbin/sysctl
.if exists(/usr/include/sys/param.h)
OSVERSION!=	${AWK} '/^\#define __FreeBSD_version/ {print $$3}' < /usr/include/sys/param.h
.elif exists(/usr/src/sys/sys/param.h)
OSVERSION!=	${AWK} '/^\#define __FreeBSD_version/ {print $$3}' < /usr/src/sys/sys/param.h
.else
OSVERSION!=	${SYSCTL} -n kern.osreldate
.endif
.endif

OPTIONS=DICT_RUBY	"Enable Ruby based dictionary module"		off \
	EST		"Enable Hyper Estraier dictionary module"	off \
	MYSQL		"Enable MySQL dictionary module"		off \
	PYTHON		"Enable Python module"				on
.if ${ARCH} == "sparc64" || ${OSVERSION} >= 700042
OPTIONS+=UNIHAN		"Enable Unihan database dictionary module"	off
.else
OPTIONS+=UNIHAN		"Enable Unihan database dictionary module"	on
.endif

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

.if defined(WITHOUT_PYTHON)
CONFIGURE_ARGS+=--with-python=no
PLIST_SUB+=	PYTHON="@comment "
.else
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygtk2
PLIST_SUB+=	PYTHON=""
.endif

.if defined(WITH_UNIHAN)
.if ${OSVERSION} >= 700042
BROKEN=		Broken with Unihan with gcc 4.2
.endif
.if ${ARCH} == "sparc64"
BROKEN=	Not buildable with Unihan on sparc64
.endif
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

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		PYTHON_VERSION=${PYTHON_VERSION:S;python;;} \
		pyexecdir=${PYTHON_SITELIBDIR} \
		GMSGFMT="${LOCALBASE}/bin/msgfmt"

.if defined(WITH_UNIHAN)
post-extract:
	cd ${WRKSRC}/module/dict && \
		${UNZIP_CMD} -qo ${DISTDIR}/Unihan.zip -d ${WRKSRC}/module/dict
.endif

.include <bsd.port.post.mk>
