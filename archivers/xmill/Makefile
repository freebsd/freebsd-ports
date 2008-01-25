# New ports collection makefile for:	XMill
# Date created:				09 May 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	xmill
DISTVERSION=	0.8
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An efficient compressor for XML

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile

USE_ZIP=	yes
USE_DOS2UNIX=	yes

PLIST_FILES=	bin/xmill bin/xdemill bin/xbmill bin/xbdemill
PORTDOCS=	COPYRIGHT.txt LICENSE.txt MANUAL.txt README.txt xmill.ps.gz

post-patch:
	@${REINPLACE_CMD} -e 's,friend,& class,' \
		${WRKSRC}/XMill/*.?pp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xmill ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xdemill ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xbmill ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xbdemill ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/paper/xmill.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.mk>
