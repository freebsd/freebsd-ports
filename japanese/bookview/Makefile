# New ports collection makefile for:	bookview
# Version required:		1.1.6
# Date created:			2 Oct 1997
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id$
#

DISTNAME=	bookview-1.1.6
PKGNAME=	ja-bookview-1.1.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/old/

MAINTAINER=	m-kasahr@sra.co.jp

RUN_DEPENDS=	${PREFIX}/bin/wish4.2jp:${PORTSDIR}/japanese/tk42

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ja-doc
CONFIGURE_ENV=	WISH=${PREFIX}/bin/wish4.2jp \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in bookview.info bookview-ja.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
