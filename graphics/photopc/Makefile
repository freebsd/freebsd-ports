PORTNAME=	photopc
PORTVERSION=	3.07
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Control cameras based on Sierra Imaging chipset and compatibles
WWW=		https://photopc.sourceforge.net/

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/epinfo \
		bin/photopc \
		include/eph_io.h \
		lib/libeph_io.a \
		share/man/man1/epinfo.1.gz \
		share/man/man1/photopc.1.gz
PORTDOCS=	README protocol.htm usage.htm

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
