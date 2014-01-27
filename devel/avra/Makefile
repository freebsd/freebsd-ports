# Created by: Wes Peters <@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avra
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Macro Assembler for Atmel AVR microcontrollers

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USES=		gmake
USE_BZIP2=	yes
MAKEFILE=	${WRKSRC}/makefiles/Makefile.linux
MAKE_ARGS=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS}" LDFLAGS=""

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/avra

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avra ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/../examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
