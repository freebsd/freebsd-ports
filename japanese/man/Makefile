# New ports collection makefile for:	jman - japanese man with EUC
# Date created:		4 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	man
PORTVERSION=	1.1j
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/ \
		${MASTER_SITE_PORTS_JP}
DISTNAME=	jp-${PORTNAME}-${PORTVERSION}

PATCH_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/
PATCHFILES=	jp-man-1.1j-ex-20020115.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	kuriyama@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/groff:${PORTSDIR}/japanese/groff \
		jless:${PORTSDIR}/japanese/less

MAKE_ENV=	GZCAT=${GZCAT} GZIP_CMD="${GZIP_CMD}"

MANLANG=	"" ja
MAN1=		jman.1 jmanpath.1 japropos.1 \
		jwhatis.1 jmakewhatis.1 jcatman.1
MAN8=		jmakewhatis.local.8 jcatman.local.8
MANCOMPRESSED=	yes

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
