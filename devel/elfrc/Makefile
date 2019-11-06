# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	elfrc
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	http://ktown.kde.org/~frerich/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Resource compiler for ELF systems

BROKEN=		unfetchable

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PLIST_FILES=	bin/elfrc
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-build:
	@${ECHO} '#define ELFRC_VERSION "${PORTVERSION}"' > ${WRKSRC}/config.h
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/elfrc ${WRKSRC}/elfrc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/elfrc ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
