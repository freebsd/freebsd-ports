PORTNAME=	chrpath
PORTVERSION=	0.18
CATEGORIES=	devel sysutils
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Tool to modify DT_RPATH in existing ELF binaries
WWW=		https://codeberg.org/pere/chrpath/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

do-test:
	cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD} check

.include <bsd.port.mk>
