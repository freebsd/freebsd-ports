# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xvmahjongg
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/../R5contrib
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mahjongg for XView with multicolored tiles

LIB_DEPENDS=	xview:${PORTSDIR}/x11-toolkits/xview

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/mahjongg2.1

MAKE_ENV=	OPENWINHOME="${LOCALBASE}" MKDIR="${MKDIR}"
ALL_TARGET=	mahjongg.swap
MAKE_JOBS_UNSAFE=	yes

MAN6=		xvmahjongg.6
PORTDOCS=	Notes README README.too
PLIST_FILES=	bin/xvmahjongg

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^XVIEWLIBDIR/s| =.*| = -L$${XVIEWROOT}/lib| ; \
		 /^CFLAGS/s| = -O | += | ; \
		 s|cc |$$(CC) |' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|cc |$$(CC) | ; \
		 s|mkdir |-$$(MKDIR) |' ${WRKSRC}/image-stuff/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} mahjongg \
		${PREFIX}/bin/xvmahjongg)
	(cd ${WRKSRC} && ${INSTALL_MAN} mahjongg.6 \
		${MAN6PREFIX}/man/man6/xvmahjongg.6)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
