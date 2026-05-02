PORTNAME=	zipmix
DISTVERSION=	20070221
CATEGORIES=	archivers
MASTER_SITES=	http://www.advsys.net/ken/util/ \
		https://BSDforge.com/projects/source/archivers/zipmix/
DISTNAME=	${PORTNAME}_src

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Produce .ZIP file from two other ones with the best compressed files
WWW=		http://www.advsys.net/ken/utils.htm

DEPRECATED=	No longer supported upstream. Replaced by archivers/archmerge
EXPIRATION_DATE=	2026-06-30

USES=		dos2unix ncurses zip
MAKEFILE=	${FILESDIR}/Makefile
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
