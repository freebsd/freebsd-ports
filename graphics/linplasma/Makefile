# New ports collection makefile for:	linplasma
# Date created:				2000-10-22
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	linplasma
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/hacks/svgalib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sinus plasma, an SVGAlib demo

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

ALL_TARGET=	${PORTNAME}
DOCFILES=	README GPL
DOCDIR=		share/doc/${PORTNAME}/
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s:PI:M_PI:g" ${WRKSRC}/linplasma.c

pre-install:
	${ECHO_CMD} "bin/linplasma" > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCFILES}
	${ECHO_CMD} -n ${DOCDIR} >> ${PLIST}
	${ECHO_CMD} ${i} >> ${PLIST}
.endfor
	${ECHO_CMD} -n "@dirrm " >> ${PLIST}
	${ECHO_CMD} ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL} -c -g wheel -o root -m 4755 ${WRKSRC}/linplasma ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
