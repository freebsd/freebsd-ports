# Created by: ijliao
# $FreeBSD$

PORTNAME=	rlwrap
DISTVERSION=	0.44
CATEGORIES=	devel
MASTER_SITES=	https://github.com/hanslub42/rlwrap/releases/download/${DISTVERSION}/

MAINTAINER=	gamato@users.sf.net
COMMENT=	Readline wrapper

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf python readline shebangfix
PYTHON_NO_DEPENDS=	yes
SHEBANG_GLOB=	*.py
python_OLD_CMD=	"/usr/bin/env python3"

GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS BUGS NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
