# New ports collection makefile for:	han
# Version required:	1.0fb
# Date created:		12 Apr 1997
# Whom:			Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

DISTNAME=	han-1.0fb
PKGNAME=	ko-han-1.0fb
CATEGORIES=	korean
MASTER_SITES=	ftp://jazz.snu.ac.kr/pub/unix/FreeBSD-kr/source/han/

MAINTAINER=	junker@jazz.snu.ac.kr

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes

post-configure:
	${SED} -e 's%%WRKSRC%%${WRKSRC}' \
	  -e 's%%PREFIX%%${PREFIX}' \
	  -e 's%%DISTDIR%%${DISTDIR}' \
	  ${FILESDIR}/dotconfig > ${WRKSRC}/.config
	${SED} -e 's%%WRKSRC%%${WRKSRC}' \
	  -e 's%%PREFIX%%${PREFIX}' \
	  -e 's%%DISTDIR%%${DISTDIR}' \
	  ${FILESDIR}/han.sh > ${WRKSRC}/han.sh

.include <bsd.port.mk>
