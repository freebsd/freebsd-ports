# New ports collection makefile for:	vMac
# Date created:				Jul 11th 1999
# Whom:					troll
#
# $FreeBSD$
#

PORTNAME=	vMac
PORTVERSION=	0.1.9.3
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.vmac.org/download/XWindows/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulates a MacPlus machine!  Runs MacOS versions up to 7.5.5

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_XORG=	x11 ice sm xext
SUB_FILES=	pkg-message

pre-patch:
	(cd ${WRKSRC} && ${SH} ${FILESDIR}/dos2unx gemulator.c)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vMac ${PREFIX}/bin
	${STRIP_CMD} ${PREFIX}/bin/vMac
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rom ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
