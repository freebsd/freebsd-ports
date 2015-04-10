# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zipmix
DISTVERSION=	20070221
CATEGORIES=	archivers
MASTER_SITES=	http://www.advsys.net/ken/util/
DISTNAME=	${PORTNAME}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produce a .ZIP file from 2 other ones with the best compressed files

BROKEN=		Checksum and size mismatch

USES=		dos2unix zip
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
