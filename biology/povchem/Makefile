# Created by: frankch@waru.life.nthu.edu.tw
# $FreeBSD$

PORTNAME=	povchem
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	biology graphics
MASTER_SITES=	http://www.chemicalgraphics.com/paul/PC_Dist/v1.00/
DISTFILES=	povchem.c \
		povchem.cfg \
		periodic.tab
DIST_SUBDIR=	povchem
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple yet powerful tool to generate POV from a PDB file

RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray-meta

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
NO_WRKSUBDIR=	yes

USES=		dos2unix

CPPFLAGS+=	-DDATADIR=\"${DATADIR}\" \
		-DSYSCONFDIR=\"${PREFIX}/etc\"

PLIST_FILES=	bin/povchem etc/povchem.cfg %%DATADIR%%/periodic.tab

post-extract:
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${TAR} -cf - ${DISTFILES}) | \
		(cd ${WRKSRC} && ${TAR} -xf -)

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/povchem.cfg

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o povchem povchem.c -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/povchem ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/povchem.cfg ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/periodic.tab ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
