# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	pencil
PORTVERSION=	0.4.4b
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}-planner/Pencil/${PORTVERSION}eta
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Pencil - a traditional 2D animation software

LICENSE=	GPLv2

LIB_DEPENDS=	libming.so:graphics/ming \
		libpng.so:graphics/png

USES=		qmake zip
USE_QT4=	gui opengl xml moc_build rcc_build
USE_GL=		gl
QMAKE_ARGS=	INCLUDEPATH+=${LOCALBASE}/include/ming
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

PLIST_FILES=	bin/pencil

PORTDOCS=	README TODO

post-patch:
	@${MKDIR} ${WRKSRC}/src/external/freebsd
	@${CP} ${FILESDIR}/src-external-freebsd-freebsd.cpp \
		${WRKSRC}/src/external/freebsd/freebsd.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Pencil ${STAGEDIR}${PREFIX}/bin/pencil
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
