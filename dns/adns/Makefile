# Created by: Kostya Lukin <lukin@okbmei.msk.su>
# $FreeBSD$

PORTNAME=	adns
PORTVERSION=	1.6.0
CATEGORIES=	dns
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Easy to use asynchronous-capable DNS client library and utilities

LICENSE=	GPLv3

BUILD_DEPENDS=	m4>=1.4.11:devel/m4

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PORTSCOUT=	skipv:1.5.0~rc0,1.5.0~rc1

BINARY_ALIAS=	m4=${LOCALBASE}/bin/gm4
LIBVERSION=	1
PLIST_SUB+=	LIBVERSION="${LIBVERSION}"

CFLAGS+=		-Ds6_addr16=__u6_addr.__u6_addr16
CFLAGS+=		-Ds6_addr32=__u6_addr.__u6_addr32

DOCS=		COPYING GPL-vs-LGPL INSTALL README \
		README.html TODO changelog

TOSTRIP=	bin/adnsheloex \
		bin/adnsresfilter \
		bin/adnslogres \
		bin/adnshost \
		lib/libadns.so.1.6

OPTIONS_DEFINE=		DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

post-install:
.for f in ${TOSTRIP}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
.endfor

.include <bsd.port.mk>
