# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zipmix
DISTVERSION=	20070221
CATEGORIES=	archivers
MASTER_SITES=	http://www.advsys.net/ken/util/ \
		https://BSDforge.com/projects/source/archivers/zipmix/
DISTNAME=	${PORTNAME}_src

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Produce .ZIP file from two other ones with the best compressed files

USES=		dos2unix ncurses zip
MAKEFILE=	${FILESDIR}/Makefile
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
