# New ports collection makefile for:	chmview
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	chmview
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	converters textproc
MASTER_SITES=	http://trexinc.narod.ru/myprogs/files/
DISTNAME=	chmview

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	Extractor from .chm files

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/src
PLIST_FILES=	bin/chmview
PORTDOCS=	chmformat.html

pre-patch:
	@${SH} ${FILESDIR}/convert.sh ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/chmview ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
