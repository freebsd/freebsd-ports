# ex:ts=8
# New ports collection makefile for:	nomarch
# Date created:			Nov 5, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nomarch
PORTVERSION=	1.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=	erwin@lansing.dk

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes

MAN1=	nomarch.1

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g ; \
		s,^PREFIX,#PREFIX,g ; \
		s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nomarch ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nomarch.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
