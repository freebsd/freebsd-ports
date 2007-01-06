# New ports collection makefile for:	ja-tomoe
# Date created:				18 Dec 2005
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tomoe
PORTVERSION=	0.5.0
#PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP} \
		ftp://ftp.unicode.org/Public/UNIDATA/:unihan
MASTER_SITE_SUBDIR=tomoe/23340
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		Unihan.zip:unihan
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Tegaki Online MOji-ninshiki Engine

USE_GNOME=	lthack gnomehack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

USE_RUBY=	yes
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/glib2.so:${PORTSDIR}/devel/ruby-glib2 \
	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv \
	${RUBY_SITELIBDIR}/suikyo/suikyo.rb:${PORTSDIR}/japanese/suikyo
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/glib2.so:${PORTSDIR}/devel/ruby-glib2

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

post-extract:
	cd ${WRKSRC}/module/dict && \
		${UNZIP_CMD} -qo ${DISTDIR}/Unihan.zip -d ${WRKSRC}/module/dict

.include <bsd.port.mk>
