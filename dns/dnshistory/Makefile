# Created by: adamw
# $FreeBSD$

PORTNAME=	dnshistory
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.stedee.id.au/files/ \
		http://launchpad.net/${PORTNAME}/${PORTVERSION}/${PORTVERSION}/+download/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Store DNS lookups to a DB

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre

USE_BDB=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	COPYING ChangeLog NEWS

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
