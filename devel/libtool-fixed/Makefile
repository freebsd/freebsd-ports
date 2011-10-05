# New ports collection makefile for:	libtool
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	libtool
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool
PKGNAMESUFFIX=	-fixed

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Generic shared library support script -- the fixed version

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	libtool-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-ltdl-install
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
INFO=		libtool
.if ${PORTNAME} != "libltdl"
MAN1=		libtool.1 libtoolize.1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sed gsed|sed|g' \
		-e 's|CC=cc|CC=${CC}|g' \
		${WRKSRC}/configure ${WRKSRC}/libltdl/configure
	@${REINPLACE_CMD} -e 's|freebsd1\*)|freebsd1.\*)|g' \
		${WRKSRC}/configure ${WRKSRC}/libltdl/configure \
		${WRKSRC}/libltdl/m4/libtool.m4

post-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f

.include <bsd.port.mk>
