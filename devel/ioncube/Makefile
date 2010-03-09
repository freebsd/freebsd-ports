# New ports collection makefile for:    ioncube
# Date created:		Fri Feb 12 21:43:10 CET 2010
# Whom:			Svyatoslav Lempert <svyatoslav.lempert@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ioncube
DISTVERSION=	3.3.10
CATEGORIES=	devel
MASTER_SITES=	http://downloads2.ioncube.com/loader_downloads/ \
		http://downloads.ioncube.com/loader_downloads/
DISTFILES=	${PORTNAME}_loaders_fre_${VER}_${ARCH_DIST}${EXTRACT_SUFX}

MAINTAINER=	svyatoslav.lempert@.gmail.com
COMMENT=	An ionCube loader for PHP code

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
USE_PHP=	yes

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700055
VER=		6
.else
VER=		7
.endif

.if ${ARCH} == i386
ARCH_DIST=	x86
.else
ARCH_DIST=	x86-64
.endif

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
