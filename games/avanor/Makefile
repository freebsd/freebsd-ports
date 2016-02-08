# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	avanor
PORTVERSION=	0.5.8
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rogue-like game with easy ADOM-like user interface

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses tar:bzip2
MAKE_ARGS=	VERSION=${PORTVERSION} DATA_DIR=${DATADIR}/ \
		LIBS="${LDFLAGS} -lncurses"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e "s|g++|${CXX}|; \
		s|CFLAGS =|CFLAGS+=|;" \
			${WRKSRC}/Makefile

	@${REINPLACE_CMD} -e "s|DATA_DIR|\"~/.avanor/\"|" \
		${WRKSRC}/helpers/hiscore.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avanor ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/manual
	${INSTALL_DATA} ${WRKSRC}/manual/* ${STAGEDIR}${DATADIR}/manual/

.include <bsd.port.mk>
