# New ports collection makefile for:	libtool
# Version required:	1.2
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id: Makefile,v 1.2 1998/09/23 16:15:53 vanilla Exp $
#

DISTNAME=	libtool-1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool

MAINTAINER=	m-kasahr@sra.co.jp

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/libtool.info ${PREFIX}/info/dir

.include <bsd.port.mk>
