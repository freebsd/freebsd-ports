# New ports collection Makefile for: povchem
# Date created:         Mar 14 1998
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	povchem
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	biology graphics
MASTER_SITES=	http://www.chemicalgraphics.com/paul/PC_Dist/v1.00/
DISTFILES=	povchem.c \
		povchem.cfg \
		periodic.tab

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple yet powerful tool to generate POV from a PDB file

RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray

NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
DIST_SUBDIR=	povchem

DEFS=		-DDATADIR=\"${PREFIX}/share/povchem\" \
		-DSYSCONFDIR=\"${PREFIX}/etc\"
PATCH_ARGS=	-l -d ${PATCH_WRKSRC} --forward --quiet -E ${PATCH_STRIP}

do-extract:
	@${MKDIR} ${WRKSRC}
.for file in ${DISTFILES}
	@${CP} ${_DISTDIR}/${file} ${WRKSRC}
.endfor

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
	${WRKSRC}/povchem.cfg
	${MV} ${WRKSRC}/povchem.c ${WRKSRC}/povchem.c.patched
	strings -1 ${WRKSRC}/povchem.c.patched > ${WRKSRC}/povchem.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${DEFS} -o povchem povchem.c -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/povchem ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/povchem.cfg ${PREFIX}/etc
	@${MKDIR} ${PREFIX}/share/povchem
	${INSTALL_DATA} ${WRKSRC}/periodic.tab ${PREFIX}/share/povchem

.include <bsd.port.mk>
