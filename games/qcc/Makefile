# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qcc
PORTVERSION=	1.01
CATEGORIES=	games devel
MASTER_SITES=	IDSOFTWARE/source
DISTNAME=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	QuakeC compiler, for building custom games of Quake

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/send
MAKEFILE=	makefile

PLIST_FILES=	bin/qcc
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@${REINPLACE_CMD} -E '/^CFLAGS/d; s/cc( -c)? \$$\(C/$$(CC)\1 \$$\(C/' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../quake-source/Makefile.include"
.include <bsd.port.mk>
