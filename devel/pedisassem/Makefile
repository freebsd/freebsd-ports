# New ports collection makefile for:	pedisassem
# Date created:				24 January 2001
# Whom:					Jun-ichiro itojun Hagino <itojun@netbsd.org>
#
# $FreeBSD$
#

PORTNAME=	pedisassem
PORTVERSION=	0.22
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Foothills/4078/
DISTNAME=	dsasmsrc

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes

USE_ZIP=	yes

post-extract:
	@${LN} -sf ${FILESDIR}/Makefile ${WRKSRC}

post-patch:
	@${PERL} -pi -e "s|\x0D|| ; s|malloc\.h|stdlib.h|" \
		${WRKSRC}/*.[ch] ${WRKSRC}/readme.txt

post-install:
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/readme.txt \
		${PREFIX}/share/doc/${PORTNAME}/README

.include <bsd.port.mk>
