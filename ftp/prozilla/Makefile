# New ports collection makefile for:	ftp/prozilla
# Date created:				Jan 24 2003
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	prozilla
PORTVERSION=	1.3.7.4
CATEGORIES=	ftp
MASTER_SITES=	http://prozilla.genesys.ro/downloads/prozilla/tarballs/

MAINTAINER=	alejandro@varnet.biz
COMMENT=	ProZilla is a fast download accelerator

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAN1=		proz.1 prozilla.1

.if !defined(NOPORTDOCS)
PORTDOCS=	ANNOUNCE AUTHORS COPYING CREDITS ChangeLog INSTALL FAQ NEWS \
		README TODO
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%Ld|%lld|g' ${WRKSRC}/src/*.c ${WRKSRC}/src/*.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
