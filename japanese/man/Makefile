# New ports collection makefile for:	jman - japanese man with EUC
# Version required:	1.1g
# Date created:		4 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.15 1998/04/17 14:39:35 kuriyama Exp $
#

DISTNAME=	jp-man-1.1g
PKGNAME=	ja-man-1.1g
CATEGORIES=	japanese
MASTER_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/ \
		ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/

MAINTAINER=	kuriyama@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/bin/groff:${PORTSDIR}/japanese/groff \
		jless:${PORTSDIR}/japanese/less

MAKE_ENV=	GZCAT=${GZCAT} GZIP_CMD="${GZIP_CMD}"

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
