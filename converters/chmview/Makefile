# New ports collection makefile for:	chmview
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	chmview
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	converters textproc
MASTER_SITES=	http://trexinc.narod.ru/myprogs/files/
DISTNAME=	chmview

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	Extractor from .chm files

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/src

pre-patch:
	@${SH} ${FILESDIR}/convert.sh ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	-@${MKDIR} ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/chmview ${PREFIX}/bin/chmview
	-@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/chmformat.html ${DOCSDIR}

.include <bsd.port.mk>
