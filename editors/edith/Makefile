PORTNAME=	edith
PORTVERSION=	1.58
PORTREVISION=	2
CATEGORIES=	editors linux
MASTER_SITES=	http://www.groenink.com/pub/edith/
DISTFILES=	edith1.55.common.tar.gz \
		edith1.58.linux-glibc.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 GUI editor for binary and plain text files

# Converted from RESTRICTED
LICENSE=	edithlicense
LICENSE_NAME=	edith
LICENSE_TEXT=	Redistribution not allowed
LICENSE_PERMS=	auto-accept

DEPRECATED=	Upstream last release was in 2000
EXPIRATION_DATE=	2024-01-16
ONLY_FOR_ARCHS=	amd64 i386

USES=		linux
USE_LINUX=	xorglibs

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/edith

EDITHDIR=	${PREFIX}/lib/edith

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/linux/edith ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EDITHDIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/edi* ${STAGEDIR}${EDITHDIR}/bin
.for i in defaults help
	@${MKDIR} ${STAGEDIR}${EDITHDIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/${i}/* ${STAGEDIR}${EDITHDIR}/${i}
.endfor
	${INSTALL_MAN} ${WRKSRC}/edith.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
