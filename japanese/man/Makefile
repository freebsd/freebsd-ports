# New ports collection makefile for:	jman - japanese man with EUC
# Version required:	1.1g
# Date created:		4 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.14 1998/03/20 16:49:19 itojun Exp $
#

DISTNAME=	jp-man-1.1g
PKGNAME=	ja-man-1.1g
CATEGORIES=	japanese
MASTER_SITES=	ftp://jaz.jp.freebsd.org/pub/FreeBSD-jp/man-jp/ \
		ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/

MAINTAINER=	kuriyama@opt.phys.waseda.ac.jp

RUN_DEPENDS=	${PREFIX}/bin/groff:${PORTSDIR}/japanese/groff \
		jless:${PORTSDIR}/japanese/less

MAKE_ENV=	GZCAT=${GZCAT} GZIP_CMD="${GZIP_CMD}"

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
