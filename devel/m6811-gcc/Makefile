# New ports collection makefile for:	m6811-gcc
# Date created:		Thu Sep 14 11:10:01 CDT 1995
# Whom:			erich@FreeBSD.org, jake@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcc
PKGNAMEPREFIX=	m6811-

PATCH_SITES=	http://home.worldnet.fr/~stcarrez/snapshots/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-m68hc1x-20000111.diffs.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/m6811-elf-as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
BUILD_DEPENDS+=	autoconf:${PORTSDIR}/devel/autoconf

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
PLIST_SUB=	GCC_VER=${PORTVERSION}
CONFIGURE_ARGS=		--prefix=${PREFIX} --target=m6811-elf   \
			--program-prefix=m6811-elf-

MAN1=		m6811-elf-g++.1 m6811-elf-g77.1 m6811-elf-gcc.1 cccp.1

.include <bsd.port.mk>
