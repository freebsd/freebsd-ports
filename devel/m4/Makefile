# New ports collection makefile for:	m4
# Version required:     1.4
# Date created:		25 October 1994
# Whom:			mr
#
# $Id: Makefile,v 1.8 1998/07/02 10:50:50 vanilla Exp $
#

DISTNAME=       m4-1.4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	m4

MAINTAINER=	ports@FreeBSD.ORG

GNU_CONFIGURE=yes
CONFIGURE_ARGS= --program-prefix=g

post-install:
	@${MKDIR} ${PREFIX}/share/examples/gm4
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${PREFIX}/share/examples/gm4
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/m4.info ${PREFIX}/info/dir

.include <bsd.port.mk>
