# New ports collection makefile for:	avida
# Date created:		17 April 2002
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	avida
PORTVERSION=	2.10.0
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	c-s@c-s.li
COMMENT=	Avida is an auto-adaptive genetic system designed for ALife research

LICENSE=	GPLv2

USE_CMAKE=	yes
USE_GCC=	4.2+
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

post-extract:
	@${RM} -f ${WRKSRC}/documentation/.[D_]*

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/work/avida ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/work/*.cfg ${WRKSRC}/work/*.org ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile: invokes i386 asm
.endif

.include <bsd.port.post.mk>
