# New ports collection makefile for:	bookview
# Version required:		2.2
# Date created:			2 Oct 1997
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id: Makefile,v 1.2 1999/01/26 02:33:01 steve Exp $
#

DISTNAME=	bookview-2.2.1
PKGNAME=	ja-bookview-2.2.1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/old/

MAINTAINER=	takamune@avrl.mei.co.jp

RUN_DEPENDS=	${PREFIX}/bin/wish8.0jp:${PORTSDIR}/japanese/tk80

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WISH=${PREFIX}/bin/wish8.0jp \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in bookview bookview-ja
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
