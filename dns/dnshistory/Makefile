PORTNAME=	dnshistory
DISTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Store DNS lookups to a DB
WWW=		https://codeberg.org/BSDforge/dnshistory

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		bdb localbase:ldflags
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${BDB_LIB_DIR}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	COPYING ChangeLog NEWS

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
