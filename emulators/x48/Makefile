# New ports collection makefile for:	x48
# Date created:		Thu Oct 24 13:10:59 CDT 1996
# Whom:			erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	x48
PORTVERSION=	0.4.1e
CATEGORIES=	emulators
MASTER_SITES=	http://www.hpcalc.org/hp48/pc/emulators/
DISTFILES=	${PORTNAME}-${PORTVERSION:S/.//g}.tgz \
		gxrom-r.zip
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION:S/.//g}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A HP48 SX/GX calculator emulator

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/e//}

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
USE_REINPLACE=	yes
ROMPATH=	${PREFIX}/share/x48

post-patch:
	@${REINPLACE_CMD} -e 's+rom.dump+${ROMPATH}/gxrom-r+' \
		${WRKSRC}/src/dump2rom.c ${WRKSRC}/src/X48.ad
post-install:
	@${MKDIR} ${ROMPATH}
	@unzip ${DISTDIR}/${DISTSUBDIR}/gxrom-r	-d ${ROMPATH}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README doc/CARDS.doc doc/ROMDump.doc
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
