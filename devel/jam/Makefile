# New ports collection makefile for:	jam
# Version required:     2.2
# Date created:		10 July 1998
# Whom:			Jeffrey Hsu <hsu@freebsd.org>
#
# $Id$
#

DISTNAME=	jam-2.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/jam/

MAINTAINER=	hsu@freebsd.org

HTML_DOCS_DIR=	${PREFIX}/share/doc/jam
HTML_DOCS=	Jam.html Jambase.html Jamfile.html Jamlang.html

do-install:
	(cd ${WRKSRC}; \
	 bin.freebsdx86/jam install; \
	 ${MKDIR} ${HTML_DOCS_DIR}; \
	 ${INSTALL_MAN} ${HTML_DOCS} ${HTML_DOCS_DIR})

.include <bsd.port.mk>
