PORTNAME=	libburn
PORTVERSION=	1.5.4
CATEGORIES=	devel
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libburnia library to read/write optical discs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*.txt

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
