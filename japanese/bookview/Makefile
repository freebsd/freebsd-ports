# New ports collection makefile for:	bookview
# Version required:		2.4.1
# Date created:			2 Oct 1997
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id: Makefile,v 1.3 1999/03/13 07:30:16 taoka Exp $
#

DISTNAME=	bookview-2.4.1
PKGNAME=	ja-bookview-2.4.1
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

.include <bsd.port.pre.mk>

pre-install:
.if !exists(${PREFIX}/info/dir)
	${CP} -p ${INFODIR}/dir-tmpl ${PREFIX}/info/dir
.endif

.include <bsd.port.post.mk>
