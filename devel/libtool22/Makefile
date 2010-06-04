# New ports collection makefile for:	libtool
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME?=	libtool
PORTVERSION=	2.2.6b
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool
DISTNAME=	libtool-${PORTVERSION}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	kwm@FreeBSD.org
COMMENT?=	Generic shared library support script

WRKSRC=		${WRKDIR}/libtool-${PORTVERSION:S|a||}
USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?= --disable-ltdl-install
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
INFO?=		libtool

post-patch:
	${REINPLACE_CMD} -e 's|sed gsed|sed|g' ${WRKSRC}/configure

.include <bsd.port.mk>
