# New ports collection Makefile for:	seed7
# Date created:				16 July 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	seed7
DISTVERSION=	05_20100606
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}.tgz
DISTNAME=	${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A high-level, extensible programming language

USE_GMAKE=	yes
USE_XORG=	x11

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile
ALL_TARGET=	hi

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g;\
	    s|`pwd`|${PREFIX}/lib/${PORTNAME}|g;\
	    s|-lX11|$${LFLAGS} -lX11|g' \
	    ${WRKSRC}/makefile
	${REINPLACE_CMD} -i '' -e 's|./hi|${PREFIX}/bin/hi|g' \
	    ${WRKSRC}/../prg/chk_all.sd7

do-configure:
	(cd ${WRKSRC} && ${GMAKE} depend)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hi ${PREFIX}/bin
	${INSTALL} -d ${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}/../lib && ${COPYTREE_SHARE} \* ${PREFIX}/lib/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/s7_comp.a ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/s7_data.a ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/seed7_05.a ${PREFIX}/lib/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	(cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}
	(cd ${WRKSRC}/../prg && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

test: install
	@echo ""
	@echo "Testing the ${PORTNAME} installation"
	@(cd ${WRKSRC}/../prg && ${PREFIX}/bin/hi chk_all)

.include <bsd.port.mk>
