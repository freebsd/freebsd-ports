# New ports collection makefile for:	bookview
# Date created:			2 Oct 1997
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	bookview
PORTVERSION=	3.0.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/

MAINTAINER=	takamune@avrl.mei.co.jp

RUN_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WISH=${PREFIX}/bin/wish8.0jp \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.mk>
