# Created by: Adam Kranzel (adam@alameda.edu)
# $FreeBSD$

PORTNAME=	slashem
PORTVERSION=	0.0.7E.7F.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/0.0.7E7F3
PKGNAMESUFFIX=	-tty
DISTNAME=	se${PORTVERSION:S/.//g:tl}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dungeon explorin', slashin', hackin' game

USES=		gmake
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES+=	pkg-deinstall
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/([A-Z])./\1/g}
MAKE_ENV+=	DATADIR="${DATADIR}"

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e \
		"s@%%DATADIR%%@${DATADIR}@g" ${WRKSRC}/include/config.h

do-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@(cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} manpages)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/slamfaq.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/sample.slashemrc ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/save

.include <bsd.port.mk>
