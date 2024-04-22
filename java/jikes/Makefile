PORTNAME=	jikes
PORTVERSION=	1.22
PORTREVISION=	3
CATEGORIES=	java
MASTER_SITES=	SF/${PORTNAME}/Jikes/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java source to byte-code compiler made available by IBM
WWW=		http://jikes.sf.net/

USES=		autoreconf gmake iconv localbase tar:bzip2
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	ac_cv_search_iconv=${ICONV_LIB} \
		ac_cv_search_libiconv_open=no

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
