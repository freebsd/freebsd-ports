# New ports collection makefile for:	acidwarp
# Date created:				2000-10-22
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	acidwarp
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/hacks/svgalib

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

ALL_TARGET=	acidwarp
DOCFILES=	README TODO Thanks
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/acidwarp

post-extract:
	${RM} ${WRKSRC}/acidwarp

post-patch:
	@${PERL} -pi -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/Makefile

pre-install:
	${ECHO} "bin/acidwarp" > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCFILES}
	${ECHO} -n "share/doc/acidwarp/" >> ${PLIST}
	${ECHO} ${i} >> ${PLIST}
.endfor
	${ECHO} "@dirrm share/doc/acidwarp" >> ${PLIST}
.endif

do-install:
	${INSTALL} -c -g wheel -o root -m 4755 ${WRKSRC}/acidwarp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/acidwarp
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/acidwarp
.endfor
.endif

.include <bsd.port.mk>
