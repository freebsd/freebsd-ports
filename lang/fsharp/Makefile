# New ports collection makefile for:    fsharp
# Date created:		2006 10 10
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fsharp
PORTVERSION=	1.9.6.16
CATEGORIES=	lang
MASTER_SITES=	http://download.microsoft.com/download/F/7/4/F74A3170-261C-4E8F-B1A8-2E352C61A89B/
DISTNAME=	fsharp

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	Functional and object-oriented language for the .NET platform

BUILD_DEPENDS=	mono>=2:${PORTSDIR}/lang/mono\
		${LOCALBASE}/lib/libgdiplus.a:${PORTSDIR}/x11-toolkits/libgdiplus
RUN_DEPENDS=	mono>=2:${PORTSDIR}/lang/mono\
		${LOCALBASE}/lib/libgdiplus.a:${PORTSDIR}/x11-toolkits/libgdiplus

PORTDIR=	lib/${PORTNAME}-${PORTVERSION}
PORTDOCS=	LICENSE-fsharp.txt README-fsharp.html doc manual
PORTDATA=	lib source

PLIST_SUB=	SUBDIR=${PORTDIR}
.if !defined(NOPORTDOCS)
PLIST_SUB+=	RMLIC="@comment "
.else
PLIST_SUB+=	RMLIC=""
.endif

WRKSRC=	${WRKDIR}/FSharp-${PORTVERSION}
USE_ZIP=	yes
RESTRICTED=	Microsoft Research Shared Source License Agreement

AOT=		Core Compiler PowerPack
WRAPPERS=	fsc fsi fslex fsyacc

post-extract:
.for wrapper in ${WRAPPERS}
	@(${ECHO} '#!${SH}' > ${WRKDIR}/${wrapper})
	@(${ECHO} '${LOCALBASE}/bin/mono ${PREFIX}/${PORTDIR}/bin/${wrapper}.exe $$*' >> ${WRKDIR}/${wrapper})
.endfor

do-build:

do-install:
.for asm in ${AOT}
	@ ${GACUTIL_INSTALL} ${WRKSRC}/bin/FSharp.${asm}.dll
.endfor
	@ ${MKDIR} ${PREFIX}/${PORTDIR} ${PREFIX}/${PORTDIR}/bin ${DOCSDIR}
	@ (cd ${WRKSRC} && ${COPYTREE_SHARE} "bin" ${PREFIX}/${PORTDIR}/)
	@ ${INSTALL_DATA} ${WRKSRC}/LICENSE-fsharp.txt ${DOCSDIR}/
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}/doc ${DOCSDIR}/manual
	@ (cd ${WRKSRC} && ${COPYTREE_SHARE} "doc manual" ${DOCSDIR}/)
	@ ${INSTALL_DATA} ${WRKSRC}/README-fsharp.html ${DOCSDIR}/
.endif
.if !defined(NOPORTDATA)
	@ ${MKDIR} ${DATADIR} ${DATADIR}/lib ${DATADIR}/source
	@ (cd ${WRKSRC} && ${COPYTREE_SHARE} "lib source" ${DATADIR}/)
.endif
.for wrapper in ${WRAPPERS}
	@ ${INSTALL_SCRIPT} ${WRKDIR}/${wrapper} ${PREFIX}/bin/
.endfor

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
