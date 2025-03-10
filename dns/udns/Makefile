PORTNAME=	udns
PORTVERSION=	0.6
CATEGORIES=	dns
MASTER_SITES=	http://www.corpit.ru/mjt/udns/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	DNS resolver library with sync and async queries
WWW=		https://www.corpit.ru/mjt/udns.html

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

USES=		pkgconfig

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	IPV6 DOCS

ALL_TARGET=	staticlib shared

PORTDOCS=	*

SHLIB_MAJOR=	0

IPV6_CONFIGURE_ENABLE=	ipv6

PKGCONFIGDIR?=	${PREFIX}/libdata/pkgconfig

post-build:
	@cd ${WRKSRC} && ${STRIP_CMD} dnsget_s ex-rdns_s rblcheck_s

post-patch:
	@${SED} -e 's|%PREFIX%|${PREFIX}|g ; s|%VERSION%|${PORTVERSION}|g' \
	  ${FILESDIR}/libudns.pc.in > ${WRKDIR}/libudns.pc

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
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${STAGEDIR}${PREFIX}/share/man/man1/${FILE}
.endfor
.for FILE in udns.3
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${STAGEDIR}${PREFIX}/share/man/man3/${FILE}
.endfor

post-install:
	${INSTALL_DATA} ${WRKDIR}/libudns.pc ${STAGEDIR}${PKGCONFIGDIR}/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in NEWS NOTES TODO
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}/${FILE}
.endfor

.include <bsd.port.mk>
