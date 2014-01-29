# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	udns
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.corpit.ru/mjt/udns/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	DNS resolver library with sync and async queries

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	IPV6 DOCS

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

ALL_TARGET=	staticlib shared

PORTDOCS=	*

SHLIB_MAJOR=	0

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-build:
	@cd ${WRKSRC} && ${STRIP_CMD} dnsget_s ex-rdns_s rblcheck_s

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libudns.so.${SHLIB_MAJOR} \
		${STAGEDIR}${PREFIX}/lib/libudns.so.${SHLIB_MAJOR}
	${LN} -sf libudns.so.${SHLIB_MAJOR} \
		${STAGEDIR}${PREFIX}/lib/libudns.so
	${INSTALL_DATA} ${WRKSRC}/udns.h ${STAGEDIR}${PREFIX}/include/udns.h
	${INSTALL_DATA} ${WRKSRC}/libudns.a ${STAGEDIR}${PREFIX}/lib/libudns.a
	${INSTALL_PROGRAM} ${WRKSRC}/dnsget_s ${STAGEDIR}${PREFIX}/bin/dnsget
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck_s ${STAGEDIR}${PREFIX}/bin/rblcheck
.for FILE in dnsget.1 rblcheck.1
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${STAGEDIR}${MANPREFIX}/man/man1/${FILE}
.endfor
.for FILE in udns.3
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${STAGEDIR}${MANPREFIX}/man/man3/${FILE}
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in NEWS NOTES TODO
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}/${FILE}
.endfor
.endif

.include <bsd.port.mk>
