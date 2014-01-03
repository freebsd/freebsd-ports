# Created by: squell@alumina.nl
# $FreeBSD$

PORTNAME=	id3mtag
PORTVERSION=	0.78
CATEGORIES=	audio
MASTER_SITES=	http://home.wanadoo.nl/squell/files/
DISTNAME=	id3-${PORTVERSION}

MAINTAINER=	squell@alumina.nl
COMMENT=	Mass tagging utility for audio files

MAN1=		id3.1
PLIST_FILES=	bin/id3

MAKEFILE=	makefile
NO_STAGE=	yes
ALL_TARGET=	build
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${PREFIX}/bin ${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/id3 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/id3.man ${MANPREFIX}/man/man1/id3.1
.if ${PORT_OPTIONS:MDOCS}
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README  ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
.	endif

.include <bsd.port.mk>
