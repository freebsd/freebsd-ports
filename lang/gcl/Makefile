# New ports collection makefile for:    gcl
# Version required:     2.2.2
# Date created:         Wed Feb  8 01:49:11  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.9 1997/10/07 09:20:05 tg Exp $
#

DISTNAME=       gcl-2.2.2
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.ma.utexas.edu/pub/gcl/ \
		${MASTER_SITE_GNU}

MAINTAINER=	jseger@freebsd.org

MAKEFILE=	makefile

pre-build:
	${RM} -rf ${WRKSRC}/info/gcl-si.info*

post-install:
	${INSTALL_DATA} ${WRKSRC}/info/gcl-si.info ${PREFIX}/info
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/gcl-si.info ${PREFIX}/info/dir

.include <bsd.port.mk>
