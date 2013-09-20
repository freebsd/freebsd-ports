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

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILE=	${WRKSRC}/makefiles/Makefile.linux
MAKE_ARGS=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS}" LDFLAGS=""

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/avra

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avra ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/../examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
