# New ports collection makefile for:	libtool
# Version required:	1.3
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id: Makefile,v 1.3 1999/01/27 07:41:08 fenner Exp $
#

DISTNAME=	libtool-1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool

MAINTAINER=	reg@shale.csir.co.za

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-ltdl-install

pre-install:
	@if [ -d ${PREFIX}/info -a ! -f ${PREFIX}/info/dir -a -f /usr/share/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi

.include <bsd.port.mk>
