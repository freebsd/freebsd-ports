# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

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
USES=		gettext pkgconfig gmake perl5
USE_LDCONFIG=	yes
USE_RUBY=	yes
USE_PERL5=	build

BUILD_DEPENDS+=	rubygem-glib2>0:${PORTSDIR}/devel/rubygem-glib2 \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS+=	rubygem-glib2>0:${PORTSDIR}/devel/rubygem-glib2

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

OPTIONS_DEFINE=		DICT_RUBY EST MYSQL PYTHON UNIHAN
OPTIONS_DEFAULT=	PYTHON
.if ${ARCH} != "sparc64" && ${OSVERSION} < 700042
OPTIONS_DEFAULT+=	UNIHAN
.endif
OPTIONS_SUB=		yes
DICT_RUBY_DESC=		Enable Ruby based dictionary module
DICT_RUBY_CONFIGURE_ENABLE=	dict-ruby
EST_DESC=		Enable Hyper Estraier dictionary module
EST_CONFIGURE_WITH=	est
MYSQL_DESC=		Enable MySQL dictionary module
MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_WITH=	mysql
PYTHON_DESC=		Enable Python module
PYTHON_USE=		PYTHON=yes GNOME=pygtk2
PYTHON_CONFIGURE_OFF=	--with-python=no
UNIHAN_DESC=		Enable Unihan database dictionary module
UNIHAN_CONFIGURE_ENABLE=	unihan

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MUNIHAN}
.if ${OSVERSION} >= 700042
BROKEN=		Broken with Unihan with gcc 4.2
.endif
.if ${ARCH} == "sparc64"
BROKEN=	Not buildable with Unihan on sparc64
.endif
MASTER_SITES+=	ftp://ftp.unicode.org/Public/UNIDATA/:unihan
DISTFILES+=	Unihan.zip:unihan
EXTRACT_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+=	\
	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv \
	${RUBY_SITELIBDIR}/suikyo/suikyo.rb:${PORTSDIR}/japanese/suikyo
.endif

CONFIGURE_ENV+=	PYTHON_VERSION=${PYTHON_VERSION:S;python;;} \
		pyexecdir=${PYTHON_SITELIBDIR} \
		GMSGFMT="${LOCALBASE}/bin/msgfmt"
CFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/ruby-${RUBY_VER} \
		-I${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}

.if ${PORT_OPTIONS:MUNIHAN}
post-extract:
	cd ${WRKSRC}/module/dict && \
		${UNZIP_CMD} -qo ${DISTDIR}/Unihan.zip -d ${WRKSRC}/module/dict
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/ge.*\.h>|glib.h>|g' \
		-e 's|glib/ga.*\.h>|glib.h>|g' \
		${WRKSRC}/lib/glib-compat-key-file.h \
		${WRKSRC}/lib/tomoe.c \
		${WRKSRC}/lib/glib-utils.h

.include <bsd.port.post.mk>
