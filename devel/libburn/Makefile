PORTNAME=	libburn
PORTVERSION=	1.5.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libburnia library to read/write optical discs
WWW=		https://dev.lovelyhq.com/libburnia/web/wiki/Libburn

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

PORTDOCS=	*.txt

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
