# New ports collection makefile for:	pedisassem
# Date created:				24 January 2001
# Whom:					Jun-ichiro itojun Hagino <itojun@netbsd.org>
#
# $FreeBSD$
#

PORTNAME=	pedisassem
PORTVERSION=	0.23
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/SiliconValley/Foothills/4078/
DISTNAME=	dsasmsrc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A disassembler for Win32 code (PE format)

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
MAKEFILE=	${FILESDIR}/Makefile

post-patch:
	@${REINPLACE_CMD} -e "s|`/usr/bin/printf '\r'`|| ; s|malloc\.h|stdlib.h|" \
		${WRKSRC}/*.[ch] ${WRKSRC}/readme.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
