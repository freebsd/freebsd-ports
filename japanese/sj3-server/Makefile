# New ports collection makefile for:	sj3-server
# Date created:		18 Aug 1998
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	sj3
PORTVERSION=	2.0.1.20
PORTREVISION=	7
CATEGORIES=	japanese
MASTER_SITES=	LOCAL/nork
PKGNAMESUFFIX=	-server

PATCH_SITES=	http://quasiquote.org/files/
PATCHFILES=	${PORTNAME}-qq-2.0.1.21.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A Japanese input method, binary part

LIB_DEPENDS=	sj3lib.1:${PORTSDIR}/japanese/sj3-lib

USE_RC_SUBR=	sj3
USE_IMAKE=	yes
SUB_FILES=	sj3_freebsd.tmpl
SUB_LIST=	DESTDIR=${DESTDIR}

MAN1=		sj3.1 sj3dic.1 sj3mkdic.1 sj3serv.1
MANLANG=	ja
MANCOMPRESSED=	no
PORTDOCS=	Nihongo.ps.Z hinsi.ms makedict.ms sj3lib.ms sj3serv.ms

POSTPATCHES=	${FILESDIR}/post-patch-Imakefile \
		${FILESDIR}/post-patch-sj3lib-Imakefile \
		${FILESDIR}/post-patch-include-Const.h \
		${FILESDIR}/post-patch-server-setup.c \
		${FILESDIR}/post-patch-server-serverrc \
		${FILESDIR}/post-patch-server-sj3serv.h \
		${FILESDIR}/post-patch-server-comuni.c
POSTPATCHES.nodocports= \
		${FILESDIR}/post-patch-doc-doc-Imakefile.nodocports

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-patch:
	cd ${WRKSRC} && ${CAT} ${POSTPATCHES} | ${PATCH}
.if defined(NOPORTDOCS)
	cd ${WRKSRC} && ${CAT} ${POSTPATCHES.nodocports} | ${PATCH}
.endif

pre-configure: apply-slist
	${INSTALL_DATA} ${WRKDIR}/sj3_freebsd.tmpl ${WRKSRC}/sj3_freebsd.tmpl

pre-su-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.post.mk>
