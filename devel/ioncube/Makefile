# New ports collection makefile for:    ioncube
# Date created:		Fri Feb 12 21:43:10 CET 2010
# Whom:			Svyatoslav Lempert <svyatoslav.lempert@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ioncube
DISTVERSION=	3.3.12
PORTREVISION=	1	# 20100405
CATEGORIES=	devel
MASTER_SITES=	http://downloads2.ioncube.com/loader_downloads/ \
		http://dl.dropbox.com/u/4211495/ioncube/
DISTFILES=	${PORTNAME}_loaders_fre_${VER}_${ARCH_DIST}${EXTRACT_SUFX}

MAINTAINER=	svyatoslav.lempert@gmail.com
COMMENT=	An ionCube loader for PHP code

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
USE_PHP=	yes

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

# Detect Version: for FreeBSD 8.x i386 install 8.x build, else using build for FreeBSD 7.x
.if ${OSVERSION} >= 800000 && ${ARCH} == i386
VER=		8
.endif
.if (${OSVERSION} >= 700000 && ${OSVERSION} < 800000) || (${OSVERSION} >= 700000 && ${ARCH} == amd64)
VER=		7
.endif
.if ${OSVERSION} < 700000
VER=		6
.endif

# Detect OS Architecture
.if ${ARCH} == amd64
ARCH_DIST=	x86-64
.else
ARCH_DIST=	x86
.endif

# Detect PHP version
.if ${PHP_VER} >= 5
PHP_INSTVER=	5.2
.else
PHP_INSTVER=	4.4
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/
	${INSTALL_DATA} ${WRKDIR}/ioncube/ioncube_loader_fre_${PHP_INSTVER}.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/ioncube_loader.so
	${INSTALL_DATA} ${WRKDIR}/ioncube/ioncube_loader_fre_${PHP_INSTVER}_ts.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/ioncube_loader_ts.so
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
