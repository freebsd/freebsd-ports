# New ports collection makefile for:   ascd
# Version required:    0.7
# Date created:                29 November 1998
# Whom:                        Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.3 1999/01/18 06:38:04 asami Exp $
#

DISTNAME=	ascd-0.7
CATEGORIES=	audio afterstep windowmaker
MASTER_SITES=	http://slashdot.org/linux/dl/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
MAN1=		ascd.1

do-build:
	(cd ${WRKSRC} && make)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ascd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Doc/ascd.man \
		${PREFIX}/man/man1/ascd.1
	${GZIP_CMD} ${PREFIX}/man/man1/ascd.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ascd
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/ascd
.endif

.include <bsd.port.mk>
