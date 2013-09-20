# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	silentbob
PORTVERSION=	2.4.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${PORTNAME}-2.4/

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Yet another sourcecode indexing tool

USES=		cmake

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/COPYING

PORTDOCS=	*
PLIST_FILES=	bin/bob

NO_STAGE=	yes
post-patch:
	@${RM} ${WRKSRC}/CMakeCache.txt
	@${REINPLACE_CMD} -e 's|/usr/lib/silent_bob/|${PREFIX}/lib/silent_bob/|' \
		${WRKSRC}/src/init.cxx

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
