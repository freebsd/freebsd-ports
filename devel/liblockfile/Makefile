# Created by: Yasuhiro KIMURA <yasu@utahime.org>
# $FreeBSD$

PORTNAME=	liblockfile
PORTVERSION=	1.16
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	yasu@utahime.org
COMMENT=	Standard lockfile library

LICENSE=		GPLv2+ LGPL21+
LICENSE_COMB=		multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/licenses/GPL-2
LICENSE_FILE_LGPL21+ =	${WRKSRC}/licenses/LGPL-2

USE_GITHUB=	yes
GH_ACCOUNT=	miquels

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-mailgroup

USE_LDCONFIG=	yes

PORTDOCS=	Changelog README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
