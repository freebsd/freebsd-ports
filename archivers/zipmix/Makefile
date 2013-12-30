# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zipmix
DISTVERSION=	20070221
CATEGORIES=	archivers
MASTER_SITES=	http://www.advsys.net/ken/util/
DISTNAME=	${PORTNAME}_src
EXTRACT_SUFX=	.zip

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Produce a .ZIP file from 2 other ones with the best compressed files

USES=		dos2unix
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
