# Created by: trevor
# $FreeBSD$

PORTNAME=	mbrola
PORTVERSION=	3.0.1
CATEGORIES=	audio accessibility linux
MASTER_SITES=	http://tcts.fpms.ac.be/synthesis/mbrola/bin/pclinux/ \
		http://www.festvox.org/mbrola/bin/pclinux/
PKGNAMEPREFIX=	linux-
DISTNAME=	mbr301h
DIST_SUBDIR=	mbrola-linux
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MBROLA speech synthesizer for Linux

DEPRECATED=	Depends on expiring audio/mbrolavox
EXPIRATION_DATE=	2018-01-27

RUN_DEPENDS=	mbrolavox>0:audio/mbrolavox

CONFLICTS=	mbrola-*
NO_BUILD=	yes
ONLY_FOR_ARCHS=	amd64 i386
NO_WRKSUBDIR=	yes
USES=		linux
RESTRICTED=	for non-commercial, non-military applications only

PLIST_FILES=	bin/mbrola
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbrola-linux-i386 ${STAGEDIR}${PREFIX}/bin/mbrola
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
