# New ports collection makefile for:	guile
# Version required:	1.3
# Date created:		2 November 1997
# Whom:			jseger@FreeBSD.org
#
# $Id: Makefile,v 1.14 1998/10/26 13:09:35 vanilla Exp $
#

DISTNAME=	guile-1.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	guile

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	YES
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
