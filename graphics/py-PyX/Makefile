# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PyX
PORTVERSION=	0.12.1
CATEGORIES=	graphics python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A Python package for the creation of encapsulated PostScript figures

LICENSE=	GPLv2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_TEX=	latex:build

OPTIONS_DEFINE=		T1CODE KPATHSEA
OPTIONS_DEFAULT=	T1CODE KPATHSEA
T1CODE_DESC=		Fast t1 font encoding/decoding
KPATHSEA_DESC=		Python wrapper around kpathsea

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MT1CODE} || ${PORT_OPTIONS:MKPATHSEA}
CFLAGS+=	-I${LOCALBASE}/include
.endif

.if ${PORT_OPTIONS:MT1CODE}
PLIST_SUB+=	T1CODE=""
.else
PLIST_SUB+=	T1CODE="@comment "
.endif

.if ${PORT_OPTIONS:MKPATHSEA}
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	KPATHSEA=""
.else
PLIST_SUB+=	KPATHSEA="@comment "
.endif

.if ${PORT_OPTIONS:MT1CODE} || ${PORT_OPTIONS:MKPATHSEA}
do-patch:
.if ${PORT_OPTIONS:MT1CODE}
	@${REINPLACE_CMD} -e 's|build_t1code=0|build_t1code=1|' ${WRKSRC}/setup.cfg
.endif
.if ${PORT_OPTIONS:MKPATHSEA}
	@${REINPLACE_CMD} -e 's|build_pykpathsea=0|build_pykpathsea=1|' ${WRKSRC}/setup.cfg
.endif
.endif

.include <bsd.port.mk>
