# New ports collection makefile for:	mecab-razil
# Date created:		2 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${MECAB_PORTNAME}
PORTVERSION=	${MECAB_PORTVERSION}
CATEGORIES=	japanese textproc
MASTER_SITES=	http://chasen.org/~taku/software/mecab/src/ \
		http://chasen.naist.jp/stable/ipadic/:ipadic
PKGNAMESUFFIX=	-razil
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${IPADIC_DISTNAME}${EXTRACT_SUFX}:ipadic

PATCH_SITES=	http://dev.razil.jp/archive/
PATCHFILES=	mecab-0.81.mte.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer with razil patch

LIB_DEPENDS=	mecab.0:${MECAB_PORTDIR}

USE_PERL5_BUILD=	yes
USE_REINPLACE=		yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}"

IPADIC_DISTNAME=	ipadic-2.5.1

.include "${.CURDIR}/../mecab/Makefile.common"

post-extract:
	${LN} -s ${WRKDIR}/${IPADIC_DISTNAME} ${WRKSRC}/dic/

post-patch:
	${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' \
			 -e 's/-O3/${CFLAGS}/' ${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's/mecab\.la/mecab-razil.la/g' \
		${WRKSRC}/src/Makefile.in

do-install:
	@${INSTALL_DATA} ${WRKSRC}/src/.libs/libmecab-razil.a ${PREFIX}/lib/
	@${INSTALL_DATA} ${WRKSRC}/src/.libs/libmecab-razil.so.0 ${PREFIX}/lib/
	@${LN} -s libmecab-razil.so.0 ${PREFIX}/lib/libmecab-razil.so

.include <bsd.port.mk>
