# Created by: Carsten Larsen <cs@innolan.dk>
# $FreeBSD$

PORTNAME=	lhasa
PORTVERSION=	0.3.1
CATEGORIES=	archivers
MASTER_SITES=	https://soulsphere.org/projects/lhasa/ \
		http://suyai.innolan.net/

MAINTAINER=	cs@innolan.dk
COMMENT=	Command line tool and library for parsing LHA archives

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf pathfix libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--program-suffix=sa
INSTALL_TARGET=	install-strip

PORTDOCS=	ChangeLog README AUTHORS TODO NEWS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
