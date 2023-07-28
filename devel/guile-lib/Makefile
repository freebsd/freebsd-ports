PORTNAME=	guile-lib
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	devel scheme
MASTER_SITES=	SAVANNAH
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Repository of useful code written in Guile Scheme
WWW=		https://www.nongnu.org/guile-lib/

LICENSE=	LGPL3 GPLv3
LICENSE_COMB=	multi

USES=		guile:2.2,3.0,flavors,build,run \
		gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-guile-site

TEST_TARGET=	check

INFO=		guile-library
INFO_PATH=	${GUILE_INFO_PATH}

# DO NOT try and add rules here to strip .go files, no matter how loudly
# testport / stage-qa shouts at you about it, because .go files (which are
# compiled bytecode) are not intended to be stripped and doing so causes
# breakage at run time.

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${GUILE_PKGCONFIG_DIR}
	${MV} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/*.pc \
	      ${STAGEDIR}${PREFIX}/${GUILE_PKGCONFIG_DIR}/

.include <bsd.port.mk>
