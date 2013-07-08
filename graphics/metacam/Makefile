# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	metacam
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Digital camera EXIF meta-information reader

USES=		gmake
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/metacam
PORTDOCS=	README.canon README.casio
MAN1=		metacam.1

ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
