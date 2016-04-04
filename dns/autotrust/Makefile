# Created by: Jaap Akkerhuis <jaap@nlnetlabs.nl>
# $FreeBSD$

PORTNAME=	autotrust
PORTVERSION=	0.3.1
PORTREVISION=	7
CATEGORIES=	dns
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/autotrust/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Tool to automatically update DNSSEC trust anchors

LIB_DEPENDS+=	libldns.so:dns/ldns \
		libunbound.so:dns/unbound

GNU_CONFIGURE=	yes
CFLAGS=		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

PLIST_FILES=	sbin/autotrust man/man8/autotrust.8.gz \
		etc/autotrust/autotrust.conf.sample

do-patch:
	${REINPLACE_CMD} \
		'45s!=!\?=!; \
		46s!^\(CFLAGS \)\(= -I.\) @CFLAGS@!\1+\2!' \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${STAGEDIR}${ETCDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
