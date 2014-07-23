# Created by: Kostya Lukin <lukin@okbmei.msk.su>
# $FreeBSD$

PORTNAME=	adns
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use asynchronous-capable DNS client library and utilities

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake

LIBVERSION=	1
PLIST_SUB+=	LIBVERSION="${LIBVERSION}"

DOCS=		COPYING GPL-vs-LGPL INSTALL LICENCE.WAIVERS README README.html TODO changelog

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/adnslogres ${STAGEDIR}${PREFIX}/bin/adnshost
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
