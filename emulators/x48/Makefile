# New ports collection makefile for:	x48
# Date created:		Thu Oct 24 13:10:59 CDT 1996
# Whom:			erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	x48
PORTVERSION=	0.4.1e
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.hpcalc.org/hp48/pc/emulators/
DISTFILES=	${PORTNAME}-${PORTVERSION:S/.//g}.tgz \
		gxrom-r.zip sxrom-e.zip
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION:S/.//g}.tgz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A HP48 SX/GX calculator emulator

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/e//}

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
USE_REINPLACE=	yes

ROMPATH=	${PREFIX}/share/x48

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's+rom.dump+${ROMPATH}/gxrom-r+' \
		${WRKSRC}/src/X48.ad
.if ${OSVERSION} > 600004
	@${REINPLACE_CMD} -e 's+cuaa+cuad+' ${WRKSRC}/src/X48.ad
.endif

post-install:
	@${MKDIR} ${ROMPATH}
	${UNZIP_CMD} ${DISTDIR}/${DISTSUBDIR}/gxrom-r -d ${ROMPATH}
	${UNZIP_CMD} -p ${DISTDIR}/${DISTSUBDIR}/sxrom-e > ${ROMPATH}/sxrom-e
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README doc/CARDS.doc doc/ROMDump.doc
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
