# New ports collection makefile for:    cmdftp
# Date created:         2003-12-28
# Whom:                 Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	cmdftp
PORTVERSION=	0.7.3
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cmdftp

MAINTAINER=	fehlner@gmx.de
COMMENT=	Command line shell-like ftp client

USE_REINPLACE=	yes

DOCS=	CHANGELOG README RELEASE

post-patch:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^CC|#CC|g ; \
		s|^CFLAGS|#CFLAGS|g ; \
		s|^PREFIX|#PREFIX|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmdftp ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
