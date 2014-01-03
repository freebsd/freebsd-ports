# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	varkon
PORTVERSION=	1.19E
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Varkon_${PORTVERSION}
DISTNAME=	Varkon_sources_${PORTVERSION}
DIST_SUBDIR=	varkon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free CAD system and applications development tool

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

WRKSRC=		${WRKDIR}/Varkon_${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/sources

USE_XORG=	xpm
USE_GL=		glu
USES=		gmake
MAKE_ENV=	PLATFORM=FreeBSD
ALL_TARGET=	# none
MAKE_JOBS_UNSAFE=	yes

VARKON_PREFIX=	${PREFIX}/lib/${PORTNAME}

NO_STAGE=	yes

.include <bsd.port.options.mk>

post-extract:
	@${FIND} ${WRKSRC} -name "*.o" -delete

do-configure:
	@${REINPLACE_CMD} -e \
		's|%%VARKON_PREFIX%%|${VARKON_PREFIX}|g ; \
		 s|%%DOCSDIR%%|${DOCSDIR}|g' ${WRKSRC}/com/english/varkon
	@${REINPLACE_CMD} -e \
		's|^PLATFORM|#PLATFORM|' ${BUILD_WRKSRC}/Makefile
	@${FIND} ${BUILD_WRKSRC} -name "Makefile.FreeBSD" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g ; \
		 s|/usr/X11R6|${LOCALBASE}|g ; \
		 s|-O[[:space:]]|| ; \
		 s|cc $$(LIBS)|$$(CC) $$(LIBS)|'

do-install:
	(cd ${WRKSRC}/com/english && ${INSTALL_SCRIPT} varkon ${PREFIX}/bin)
	@${MKDIR} ${VARKON_PREFIX}
.for i in erm lib mdf
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${VARKON_PREFIX})
.endfor
	@${MKDIR} ${VARKON_PREFIX}/bin
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} * ${VARKON_PREFIX}/bin)
	@${MKDIR} ${VARKON_PREFIX}/cnf
.for i in fnt icons plt tol
	@(cd ${WRKSRC}/cnf && ${COPYTREE_SHARE} ${i} ${VARKON_PREFIX}/cnf)
.endfor
	@${MKDIR} ${VARKON_PREFIX}/cnf/ini
	(cd ${WRKSRC}/cnf/ini/english && ${INSTALL_DATA} linux \
		${VARKON_PREFIX}/cnf/ini/freebsd)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}	#Varkon Manual
	@(cd ${WRKSRC}/man && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
