# New ports collection makefile for:   indent
# Version required:    2.2.2
# Date created:        28 August 1997
# Whom:                Kapil Chowksey <kchowksey@hss.hns.com>
#
# $FreeBSD$
#

DISTNAME=	indent-2.2.2
PKGNAME=	gindent-2.2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	indent

MAINTAINER=	kchowksey@hss.hns.com

GNU_CONFIGURE=	yes

MAN1=		indent.1

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
