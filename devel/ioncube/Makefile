# Created by: Svyatoslav Lempert <svyatoslav.lempert@gmail.com>
# $FreeBSD$

PORTNAME=	ioncube
DISTVERSION=	4.7.5
CATEGORIES=	devel
MASTER_SITES=	http://downloads3.ioncube.com/loader_downloads/ \
		http://dl.ispsystem.info/ioncube/${DISTVERSION}/ \
		http://downloads2.ioncube.com/loader_downloads/
DISTNAME=	${PORTNAME}_loaders_fre_${VER}_${ARCH:S,i386,x86,:S,amd64,x86-64,}
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	svyatoslav.lempert@gmail.com
COMMENT=	Loader for ionCube-encoded PHP files

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
USES=	tar:bzip2
USE_PHP=	yes

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}

VER=	9
IGNORE_DragonFly=	is unsupported on DragonFly

PHP_INSTVER=	${PHP_VERSION:C/^([0-9]+\.[0-9]+).*/\1/}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/
	${INSTALL_DATA} ${WRKSRC}/ioncube_loader_fre_${PHP_INSTVER}.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/ioncube_loader.so
	${INSTALL_DATA} ${WRKSRC}/ioncube_loader_fre_${PHP_INSTVER}_ts.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/ioncube/ioncube_loader_ts.so

.include <bsd.port.mk>
