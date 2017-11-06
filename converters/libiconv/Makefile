# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libiconv
PORTVERSION=	1.14
PORTREVISION=	11
CATEGORIES=	converters devel
MASTER_SITES=	GNU

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Character set conversion library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-nls \
		--docdir=${DOCSDIR} \
		am_cv_func_iconv=no
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
USES=		libtool
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS ENCODINGS PATCHES
OPTIONS_DEFAULT=ENCODINGS
ENCODINGS_DESC=	Include extra character sets
PATCHES_DESC=	Apply patches to fix CP932, add EUCJP-MS

ENCODINGS_CONFIGURE_ENABLE=	extra-encodings

PATCHES_PATCH_SITES=	http://apolloron.org/software/libiconv-1.14-ja/ \
			LOCAL/kwm
PATCHES_PATCHFILES=	${DISTNAME}-ja-1.patch.gz:-p1

post-patch:
	@${REINPLACE_CMD} -e 's:ei_ksc5601:ei_euc_kr:g' ${WRKSRC}/lib/aliases.h
	@${REINPLACE_CMD} -e 's:gawk:awk:g' ${WRKSRC}/configure \
		${WRKSRC}/libcharset/configure \
		${WRKSRC}/preload/configure

.include <bsd.port.mk>
