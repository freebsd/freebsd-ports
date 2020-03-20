# $FreeBSD$

PORTNAME=	qr-code-generator
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High-quality QR Code generator library

LICENSE=	MIT

USES=		compiler:c++11-lang gmake

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	nayuki
GH_PROJECT=	QR-Code-generator
GH_TAGNAME=	67c6246

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${REINPLACE_CMD} -e 's,$$(DESTDIR)/usr,${STAGEDIR}${PREFIX},' ${WRKSRC}/c/Makefile
	${REINPLACE_CMD} -e 's,$$(DESTDIR)/usr,${STAGEDIR}${PREFIX},' ${WRKSRC}/cpp/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libqrcodegen.so.${PORTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libqrcodegencpp.so.${PORTVERSION}

.include <bsd.port.mk>
