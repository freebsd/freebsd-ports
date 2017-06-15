# Created by: Kostya Lukin <lukin@okbmei.msk.su>
# $FreeBSD$

PORTNAME=	adns
PORTVERSION=	1.5.1
CATEGORIES=	dns
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Easy to use asynchronous-capable DNS client library and utilities

LICENSE=	GPLv3

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PORTSCOUT=	skipv:1.5.0~rc0,1.5.0~rc1

LIBVERSION=	1
PLIST_SUB+=	LIBVERSION="${LIBVERSION}"

BUILD_DEPENDS+=		gm4:devel/m4
CFLAGS+=		-Ds6_addr16=__u6_addr.__u6_addr16
CFLAGS+=		-Ds6_addr32=__u6_addr.__u6_addr32
MAKE_FLAGS+=		M4=gm4

DOCS=		COPYING GPL-vs-LGPL INSTALL README \
		README.html TODO changelog

TOSTRIP=	bin/adnsheloex \
		bin/adnsresfilter \
		bin/adnslogres \
		bin/adnshost \
		lib/libadns.so.1

OPTIONS_DEFINE=		DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

post-install:
.for f in ${TOSTRIP}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
.endfor

.include <bsd.port.mk>
