# New ports collection makefile for:	m6811-gcc
# Date created:		Thu Sep 14 11:10:01 CDT 1995
# Whom:			erich@FreeBSD.org, jake@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcc
PKGNAMEPREFIX=	m6811-

PATCH_SITES=	http://stephane.carrez.free.fr/snapshots/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-m68hc1x-20010922.diffs.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The gcc-2.95.2 cross-compiler for the 6811

BUILD_DEPENDS=	${LOCALBASE}/bin/m6811-elf-as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

BROKEN=		"Incorrect pkg-plist (removes files not installed by this port)"
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

# Configuration alpha-unknown-freebsdelf not supported
# Configuration sparc64-unknown-freebsdelf not supported
#	compilation stops with intermal compiler errors.
ONLY_FOR_ARCHS=	i386
MANUAL_PACKAGE_BUILD=	Path problem to autoheader on bento

WANT_AUTOCONF_VER=253
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
.if defined(_CPUCFLAGS) && !empty(_CPUCFLAGS)
CFLAGS:=	${CFLAGS:S/${_CPUCFLAGS}//g}
.endif
PLIST_SUB=	GCC_VER=${PORTVERSION}
BREAKS_IF_PEDANTIC=	yes
CONFIGURE_ARGS=		--prefix=${PREFIX} --target=m6811-elf   \
			--program-prefix=m6811-elf-

MAN1=		m6811-elf-g++.1 m6811-elf-g77.1 m6811-elf-gcc.1 cccp.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

post-patch:
	@${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.sed
	${SED} -e "s/TARGET_CONFIGDIRS = libiberty/TARGET_CONFIGDIRS =/" \
		${WRKSRC}/Makefile.in.sed > ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
