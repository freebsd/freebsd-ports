# New ports collection makefile for:	jman - japanese man with EUC
# Version required:	1.1h
# Date created:		4 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	jp-man-1.1h
PKGNAME=	ja-man-1.1h
CATEGORIES=	japanese
MASTER_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/ \
		${MASTER_SITE_PORTS_JP}

MAINTAINER=	kuriyama@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/bin/groff:${PORTSDIR}/japanese/groff \
		jless:${PORTSDIR}/japanese/less

MAKE_ENV=	GZCAT=${GZCAT} GZIP_CMD="${GZIP_CMD}"

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
