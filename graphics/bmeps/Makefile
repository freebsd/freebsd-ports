# New ports collection makefile for:	bmeps
# Date created:				6 Jan 2004
# Whom:					Hideyuki KURASHINA <rushani@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmeps
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	corky1951@comcast.net
COMMENT=	Convert bitmap images (PNG/JPEG/NetPBM) to EPS

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		netpbm.1:${PORTSDIR}/graphics/netpbm

CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include"
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		bmeps.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bmeps ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bmeps.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/bmepsoe.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/jpgeps.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/pngeps.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/pnmeps.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libbmeps.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/man1/bmeps.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.tex ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/EXAMPLES/*.bb ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/EXAMPLES/*.jpg ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/EXAMPLES/*.ps ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/EXAMPLES/*.tex ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/DOCU/EXAMPLES/*.txt ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
