# New ports collection makefile for:   indent
# Version required:    2.1.1
# Date created:        28 August 1997
# Whom:                Kapil Chowksey <kchowksey@hss.hns.com>
#
# $Id: Makefile,v 1.5 1999/07/09 00:28:51 cpiazza Exp $
#

DISTNAME=      indent-2.1.1
CATEGORIES=    devel
MASTER_SITES=  ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	indent

MAINTAINER=    kchowksey@hss.hns.com

GNU_CONFIGURE=	yes

MAN1=          indent.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/indent ${PREFIX}/bin/gindent
	${INSTALL_DATA} ${WRKSRC}/indent.info ${PREFIX}/info
	${INSTALL_MAN} ${WRKSRC}/indent.1 ${PREFIX}/man/man1

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	@install-info ${PREFIX}/info/indent.info ${PREFIX}/info/dir

.include <bsd.port.mk>
