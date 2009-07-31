# New ports collection makefile for:	autopano-sift
# Date created:				11 April 2006
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	autopano-sift
PORTVERSION=	2.4
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://user.cs.tu-berlin.de/~nowozin/autopano-sift/

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Automatic panorama control point generation tool

RESTRICTED=	May be covered by patents

LIB_DEPENDS=	gdiplus:${PORTSDIR}/x11-toolkits/libgdiplus

WRKSRC=		${WRKDIR}/${DISTNAME}/src
SUB_FILES=	autopano

USE_GMAKE=	yes
USE_GNOME=	gtksharp10

MAN1=		autopano-complete.1 \
		autopano-complete.old.1 \
		autopano.1 \
		autopanog.1 \
		generatekeys.1 \
		showone.1 \
		showtwo.1
MAN7=		autopano-sift.7

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL} ${WRKSRC}/bin/ICSharpCode.SharpZipLib.dll ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/autopano-complete.sh ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/autopano-complete.old.sh ${DATADIR}/
	${INSTALL} ${WRKSRC}/bin/autopano.exe ${DATADIR}/
	${INSTALL} ${WRKSRC}/bin/autopanog.exe ${DATADIR}/
	${INSTALL} ${WRKSRC}/bin/generatekeys-sd.exe ${DATADIR}/
	${INSTALL} ${WRKSRC}/bin/generatekeys.exe ${DATADIR}/
	${INSTALL} ${WRKSRC}/bin/libsift.dll ${DATADIR}/
	${INSTALL} ${WRKSRC}/bin/showone.exe ${DATADIR}/
	${INSTALL} ${WRKSRC}/bin/showtwo.exe ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/autopano ${PREFIX}/bin/autopano
	${LN} ${PREFIX}/bin/autopano ${PREFIX}/bin/autopanog
	${LN} ${PREFIX}/bin/autopano ${PREFIX}/bin/generatekeys-sd
	${LN} ${PREFIX}/bin/autopano ${PREFIX}/bin/generatekeys
	${LN} ${PREFIX}/bin/autopano ${PREFIX}/bin/showone
	${LN} ${PREFIX}/bin/autopano ${PREFIX}/bin/showtwo
	${LN} -s ${DATADIR}/autopano-complete.sh ${PREFIX}/bin/autopano-complete
	${LN} -s ${DATADIR}/autopano-complete.old.sh ${PREFIX}/bin/autopano-complete.old
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/autopano-complete.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/autopano-complete.old.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/autopano.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/autopanog.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/generatekeys.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/showone.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/showtwo.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/autopano-sift.7 ${PREFIX}/man/man7/

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
