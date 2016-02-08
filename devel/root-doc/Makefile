# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	root-doc
PORTVERSION=	5.02
CATEGORIES=	devel science math
MASTER_SITES=	ftp://root.cern.ch/root/
DISTNAME=	html${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML Documentation for Root framework

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/htmldoc
PLIST=		${WRKDIR}/pkg-plist

pre-install:
	@cd ${WRKSRC} && ${FIND} . \( -type f -or -type l \) -print | \
		${SED} -e 's|^\.|%%DOCSDIR%%|' > ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
