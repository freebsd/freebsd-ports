# New ports collection makefile for:	han
# Version required:	1.0fb
# Date created:		12 Apr 1997
# Whom:			Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id$
#

DISTNAME=	han-1.0fb
PKGNAME=	kr-han-1.0fb
CATEGORIES=	korean
MASTER_SITES=	ftp://jazz.snu.ac.kr/pub/unix/FreeBSD-kr/source/han/

MAINTAINER=	junker@jazz.snu.ac.kr

USE_GMAKE=	yes

post-configure:
	sed -e 's%%WRKSRC%%${WRKSRC}' \
	  -e 's%%PREFIX%%${PREFIX}' \
	  -e 's%%DISTDIR%%${DISTDIR}' \
	  files/dotconfig > ${WRKSRC}/.config
	sed -e 's%%WRKSRC%%${WRKSRC}' \
	  -e 's%%PREFIX%%${PREFIX}' \
	  -e 's%%DISTDIR%%${DISTDIR}' \
	  files/han.sh > ${WRKSRC}/han.sh

.include <bsd.port.mk>
