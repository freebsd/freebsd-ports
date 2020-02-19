# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomoe
PORTVERSION=	0.6.0
PORTREVISION=	7
CATEGORIES=	japanese
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Tegaki Online MOji-ninshiki Engine

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

GNU_CONFIGURE=	yes
USES=		gettext gmake gnome libtool pathfix perl5 pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PERL5=	build

CONFIGURE_ARGS=	--with-python=no
CONFIGURE_ENV=	GMSGFMT="${LOCALBASE}/bin/msgfmt"
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=		DICT_RUBY EST MYSQL RUBY UNIHAN
OPTIONS_SUB=		yes
DICT_RUBY_DESC=		Enable Ruby based dictionary module
DICT_RUBY_CONFIGURE_ENABLE=	dict-ruby
EST_DESC=		Enable Hyper Estraier dictionary module
EST_CONFIGURE_WITH=	est
MYSQL_DESC=		Enable MySQL dictionary module
MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql
RUBY_DESC=		Enable Ruby module
RUBY_BROKEN=		Does not build
RUBY_USE=		RUBY=yes
RUBY_CONFIGURE_OFF=	--with-ruby=no
RUBY_BUILD_DEPENDS=	rubygem-glib2>0:devel/rubygem-glib2
RUBY_RUN_DEPENDS=	rubygem-glib2>0:devel/rubygem-glib2
RUBY_CFLAGS=		-I${LOCALBASE}/include/ruby-${RUBY_VER} \
			-I${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}
UNIHAN_DESC=		Enable Unihan database dictionary module
UNIHAN_BROKEN=		Does not build
UNIHAN_MASTER_SITES=	ftp://ftp.unicode.org/Public/UNIDATA/:unihan
UNIHAN_DISTFILES=	Unihan.zip:unihan
UNIHAN_EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip
UNIHAN_BUILD_DEPENDS=	\
	${RUBY_SITEARCHLIBDIR}/uconv.so:japanese/ruby-uconv \
	${RUBY_SITELIBDIR}/suikyo/suikyo.rb:japanese/suikyo
UNIHAN_USE=		RUBY=yes
UNIHAN_CONFIGURE_ENABLE=unihan

post-extract-UNIHAN-on:
	cd ${WRKSRC}/module/dict && \
		${UNZIP_CMD} -qo ${DISTDIR}/Unihan.zip -d ${WRKSRC}/module/dict

post-patch:
	@${REINPLACE_CMD} -e 's|glib/ge.*\.h>|glib.h>|g' \
		-e 's|glib/ga.*\.h>|glib.h>|g' \
		${WRKSRC}/lib/glib-compat-key-file.h \
		${WRKSRC}/lib/tomoe.c \
		${WRKSRC}/lib/glib-utils.h

.include <bsd.port.mk>
