# New ports collection makefile for:	motogt
# Date created:		23 Sep 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	motogt
PORTVERSION=	20110505
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/motogt/
DISTNAME=	MotoGT-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D top-viewed motorcycle racing game

LIB_DEPENDS=	sfml-system.1:${PORTSDIR}/devel/sfml \
		png.6:${PORTSDIR}/graphics/png

LICENSE=	GPLv2 CCbySA
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/doc/gpl.txt
LICENSE_NAME_CCbySA=	Creative Commons Attribution-ShareAlike
LICENSE_PERMS_CCbySA=	${_LICENSE_PERMS_DEFAULT}
LICENSE_FILE_CCbySA=	${WRKSRC}/doc/cc-by-sa.txt

USE_ZIP=	yes
BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	Makefile.lnx
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
SUB_FILES=	motogt

PLIST_FILES=	bin/${PORTNAME} libexec/MotoGT.bin
PORTDATA=	*

WRKSRC=		${WRKDIR}/MotoGT

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MotoGT.bin ${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKDIR}/motogt ${PREFIX}/bin/
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR}/
.endif

.include <bsd.port.mk>
