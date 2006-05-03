# New ports collection makefile for:	big5con
# Date created:		07 Jan 1997
# Whom:			Hung-Chi Chu <hcchu@r350.ee.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	big5con
PORTVERSION=	0.92h
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Big5 Chinese console

ONLY_FOR_ARCHS=	i386

post-patch:
	@${REINPLACE_CMD} -e 's,/dev/vga,/dev/ttyv0,g' ${WRKSRC}/src/*c
	@${REINPLACE_CMD} -e 's,GetShmem(),GetShmem(char),g' ${WRKSRC}/src/fnld.c
	@${REINPLACE_CMD} -e 's,#endif.*,#endif,g' ${WRKSRC}/include/ksymdef.h
	@${REINPLACE_CMD} -e 's,TOPDIR,PREFIX,g' ${WRKSRC}/big5con.mk

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
