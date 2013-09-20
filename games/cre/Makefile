# Created by: alepulver
# $FreeBSD$

PORTNAME=	cre
DISTVERSION=	1.2beta_r2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-dev/1.2%20BETA%2C%20Release%202
DISTNAME=	${PORTNAME}_${DISTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Corewars Redcode Evolver

LICENSE=	GPLv2

USE_DOS2UNIX=	../*.txt
WRKSRC=		${WRKDIR}/src

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	*.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}
	@cd ${WRKDIR} && ${MV} "CRE Manual.txt" CRE_Manual.txt && \
		${MV} "Exhaust README.txt" Exhaust_README.txt

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e '/memwatch\.h/d' \
		asm.c pspace.c sim.c
	@cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|random[[:blank:]]*(|myrandom(|' \
		battler.c generator.c globals.h Main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKDIR}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
