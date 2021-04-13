# Created by: Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>

PORTNAME=	sj3
PORTVERSION=	2.0.1.20
PORTREVISION=	8
CATEGORIES=	japanese
MASTER_SITES=	LOCAL/nork
PKGNAMESUFFIX=	-lib

PATCH_SITES=	http://quasiquote.org/files/
PATCHFILES=	${PORTNAME}-qq-2.0.1.21.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese input method, library part

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/COPYING

USES=		imake:noman
USE_LDCONFIG=	yes
SUB_FILES=	sj3_freebsd.tmpl
SUB_LIST=	DESTDIR=${DESTDIR}

PLIST_FILES=	include/sj3lib.h \
		lib/libsj3lib.a \
		lib/libsj3lib.so \
		lib/libsj3lib.so.1

POSTPATCHES=	${FILESDIR}/post-patch-Imakefile \
		${FILESDIR}/post-patch-include-Const.h

post-patch:
	cd ${WRKSRC} && ${CAT} ${POSTPATCHES} | ${PATCH}

pre-configure:
	${INSTALL_DATA} ${WRKDIR}/sj3_freebsd.tmpl ${WRKSRC}/sj3_freebsd.tmpl

.include <bsd.port.mk>
