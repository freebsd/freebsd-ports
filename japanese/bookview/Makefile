# New ports collection makefile for:	bookview
# Version required:		2.4.3
# Date created:			2 Oct 1997
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id: Makefile,v 1.4 1999/04/16 04:54:21 taoka Exp $
#

DISTNAME=	bookview-2.4.3
PKGNAME=	ja-bookview-2.4.3
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/old/ \
		ftp://ftp.mei.co.jp/free/others/Dictionary/ndtp/bookview/

MAINTAINER=	takamune@avrl.mei.co.jp

RUN_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WISH=${PREFIX}/bin/wish8.0jp \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.mk>
