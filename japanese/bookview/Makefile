# New ports collection makefile for:	bookview
# Version required:		2.2
# Date created:			2 Oct 1997
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id$
#

DISTNAME=	bookview-2.2
PKGNAME=	ja-bookview-2.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/old/

MAINTAINER=	m-kasahr@sra.co.jp

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
