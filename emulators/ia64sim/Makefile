# Created by: David O'Brien <obrien@NUXI.com>
# $FreeBSD$

PORTNAME=	ia64sim
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.boo.net/~jasonp/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IA64 simulator (Intel(R) Architecture 64)

USE_ZIP=	yes
USES=		gmake
MAKEFILE=	makefile.unx
MAKE_ARGS=	CC="${CC}"

WRKSRC=		${WRKDIR}/home/chuck/ia64simcc

PLIST_FILES=	bin/ia64sim
PORTDOCS=	ia64user.txt readme

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

pre-build:
	${RM} -f ${WRKSRC}/obj/*.o ${WRKSRC}/ia64sim

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ia64user.txt ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
