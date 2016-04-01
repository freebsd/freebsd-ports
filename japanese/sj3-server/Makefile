# Created by: Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
# $FreeBSD$

PORTNAME=	sj3
PORTVERSION=	2.0.1.20
PORTREVISION=	8
CATEGORIES=	japanese
MASTER_SITES=	LOCAL/nork
PKGNAMESUFFIX=	-server

PATCH_SITES=	http://quasiquote.org/files/
PATCHFILES=	${PORTNAME}-qq-2.0.1.21.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese input method, binary part

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/COPYING

LIB_DEPENDS=	libsj3lib.so:japanese/sj3-lib

USES=		imake
USE_RC_SUBR=	sj3
PLIST_SUB=	USERS=${USERS} GROUPS=${GROUPS}
SUB_FILES=	sj3_freebsd.tmpl
SUB_LIST=	DESTDIR=${DESTDIR}
CFLAGS+=	-Wno-return-type
USERS=		_sj3
GROUPS=		_sj3
PORTDOCS=	Nihongo.ps.Z hinsi.ms makedict.ms sj3lib.ms sj3serv.ms

POSTPATCHES=	${FILESDIR}/post-patch-Imakefile \
		${FILESDIR}/post-patch-sj3lib-Imakefile \
		${FILESDIR}/post-patch-sj3-sj3.c \
		${FILESDIR}/post-patch-dict-dict-Imakefile \
		${FILESDIR}/post-patch-include-Const.h \
		${FILESDIR}/post-patch-server-setup.c \
		${FILESDIR}/post-patch-server-serverrc \
		${FILESDIR}/post-patch-server-sj3serv.h \
		${FILESDIR}/post-patch-server-comuni.c
POSTPATCHES.nodocports= \
		${FILESDIR}/post-patch-doc-doc-Imakefile.nodocports

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	cd ${WRKSRC} && ${CAT} ${POSTPATCHES} | ${PATCH}
.if !${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${CAT} ${POSTPATCHES.nodocports} | ${PATCH}
.endif

pre-configure: apply-slist
	${INSTALL_DATA} ${WRKDIR}/sj3_freebsd.tmpl ${WRKSRC}/sj3_freebsd.tmpl

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/sj3/dict/user

.include <bsd.port.mk>
