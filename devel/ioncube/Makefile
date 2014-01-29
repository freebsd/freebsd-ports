# Created by: Svyatoslav Lempert <svyatoslav.lempert@gmail.com>
# $FreeBSD$

PORTNAME=	ioncube
DISTVERSION=	4.5.1
CATEGORIES=	devel
MASTER_SITES=	http://downloads3.ioncube.com/loader_downloads/ \
		http://dl.ispsystem.info/ioncube/${DISTVERSION}/ \
		http://downloads2.ioncube.com/loader_downloads/
DISTNAME=	${PORTNAME}_loaders_fre_${VER}_${ARCH:S,i386,x86,:S,amd64,x86-64,}

MAINTAINER=	svyatoslav.lempert@gmail.com
COMMENT=	Loader for ionCube-encoded PHP files

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
USE_BZIP2=	yes
USE_PHP=	yes

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
# FreeBSD 10 is unsupported
.if ${OSVERSION} >= 1000000
IGNORE=	is unsupported on FreeBSD 10
.endif

# Detect OS version for distname
VER=	8
.if ${OSVERSION} >= 900000
VER=	9
.endif
.else
IGNORE= is unsupported on ${OPSYS}
.endif

PHP_INSTVER=	${PHP_VERSION:C/^([0-9]+\.[0-9]+).*/\1/}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/
	${INSTALL_DATA} ${WRKSRC}/ioncube_loader_fre_${PHP_INSTVER}.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/ioncube_loader.so
	${INSTALL_DATA} ${WRKSRC}/ioncube_loader_fre_${PHP_INSTVER}_ts.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/ioncube_loader_ts.so

.include <bsd.port.post.mk>
