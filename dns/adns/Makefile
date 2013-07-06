# Created by: Kostya Lukin <lukin@okbmei.msk.su>
# $FreeBSD$

PORTNAME=	adns
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Easy to use asynchronous-capable DNS client library and utilities

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

USES=	gmake

LIBVERSION=	1
PLIST_SUB+=	LIBVERSION="${LIBVERSION}"

DOCS=		COPYING GPL-vs-LGPL INSTALL LICENCE.WAIVERS README README.html TODO changelog

.include <bsd.port.options.mk>

post-install:
	${STRIP_CMD} ${PREFIX}/bin/adnslogres ${PREFIX}/bin/adnshost
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
