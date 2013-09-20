# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	glsfcave
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://user.ecc.u-tokyo.ac.jp/~g650192/glsfcave/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Control a ribbon to avoid hitting walls

USE_BZIP2=	yes
USE_GL=		glut

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PLIST_FILES=	bin/glsfcave

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} -o glsfcave main.c -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib -lglut -lGL -lGLU

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glsfcave ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
