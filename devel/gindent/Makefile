# New ports collection makefile for:   indent
# Version required:    2.1.0
# Date created:        28 August 1997
# Whom:                Kapil Chowksey <kchowksey@hss.hns.com>
#
# $Id: Makefile,v 1.4 1999/06/28 19:12:06 cpiazza Exp $
#

DISTNAME=      indent-2.1.0
CATEGORIES=    devel
MASTER_SITES=  ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	indent

MAINTAINER=    kchowksey@hss.hns.com

GNU_CONFIGURE=	yes

MAN1=          indent.1

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	@install-info ${PREFIX}/info/indent.info ${PREFIX}/info/dir

.include <bsd.port.mk>
