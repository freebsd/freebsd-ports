# New ports collection makefile for:	xchat-ja
# Date created:		30 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../irc/xchat

CATEGORIES=	japanese
PATCH_SITES=	http://northeye.org/~takuo/xchat-ja/
PATCHFILES=	${PORTNAME}-${PORTVERSION}.ja.3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	iconv.1:${PORTSDIR}/converters/iconv

FILESDIR=	${.CURDIR}/files

CONFIGURE_ARGS=	--enable-japanese-conv # --enable-ipv6
MAKE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv -lintl"

pre-patch:
	${PERL} -i -pe 's/-b&h-lucidatypewriter-medium-r-normal-\*-\*-120-\*-\*-m-\*-\*-\*/$$&,-default-*ng-medium-r-normal--14-*,*/' ${WRKSRC}/src/common/cfgfiles.c

pre-build:
	${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in ${WRKSRC}/configure ${WRKSRC}/config.status

.include "${MASTERDIR}/Makefile"
