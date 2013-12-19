# Created by: bms
# $FreeBSD$

PORTNAME=	chrpath
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	devel sysutils
MASTER_SITES=	http://ftp.tux.org/pub/X-Windows/ftp.hungry.com/chrpath/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to modify DT_RPATH in existing ELF binaries

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

USES=		fmake

PLIST_FILES=	bin/chrpath man/man1/chrpath.1.gz

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.	for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.	endfor

.include <bsd.port.mk>
