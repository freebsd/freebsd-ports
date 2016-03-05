# Created by: bms
# $FreeBSD$

PORTNAME=	chrpath
PORTVERSION=	0.16
CATEGORIES=	devel sysutils
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to modify DT_RPATH in existing ELF binaries

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/chrpath man/man1/chrpath.1.gz
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
