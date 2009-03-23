# New ports collection makefile for:	udns
# Date created:			Sat May 24, 2008
# Whom:				Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	udns
PORTVERSION=	0.0.9
CATEGORIES=	dns
MASTER_SITES=	http://www.corpit.ru/mjt/udns/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	DNS resolver library with sync and async queries

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

OPTIONS=	IPV6 "Enable IPv6 support" on

ALL_TARGET=	staticlib shared

PORTDOCS=	*

CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"

SHLIB_MAJOR=	0

MAN1=		dnsget.1 rblcheck.1
MAN3=		udns.3

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-build:
	@cd ${WRKSRC} && ${STRIP_CMD} dnsget_s ex-rdns_s rblcheck_s

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libudns.so.${SHLIB_MAJOR} \
		${PREFIX}/lib/libudns.so.${SHLIB_MAJOR}
	${LN} -sf ${PREFIX}/lib/libudns.so.${SHLIB_MAJOR} \
		${PREFIX}/lib/libudns.so
	${INSTALL_DATA} ${WRKSRC}/udns.h ${PREFIX}/include/udns.h
	${INSTALL_DATA} ${WRKSRC}/libudns.a ${PREFIX}/lib/libudns.a
	${INSTALL_PROGRAM} ${WRKSRC}/dnsget_s ${PREFIX}/bin/dnsget
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck_s ${PREFIX}/bin/rblcheck
.for FILE in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${MANPREFIX}/man/man1/${FILE}
.endfor
.for FILE in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${MANPREFIX}/man/man3/${FILE}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in COPYING.LGPL NEWS NOTES TODO
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
.endif

.include <bsd.port.post.mk>
