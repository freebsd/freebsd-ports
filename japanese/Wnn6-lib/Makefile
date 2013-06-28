# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Wnn6-lib
PORTVERSION=	2000.9.1
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/Wnn6/sdk_source/
DISTNAME=	Wnn6-SDK

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Wnn6 client library

USES=		imake
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/src/contrib/im/Xsi
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/config/Project.tmpl \
		${WRKSRC}/config/X11.tmpl \
		${WRKSRC}/Makefile.ini

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}  make World -f Makefile.ini

post-install:
	${LN} -sf libwnn6_fromsrc.a ${PREFIX}/lib/libwnn6.a
	${MKDIR} ${PREFIX}/include/wnn6/wnn
	${INSTALL_DATA} ${WRKSRC}/Wnn/include/*.h ${PREFIX}/include/wnn6/wnn
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
