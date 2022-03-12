PORTNAME=	pounce
DISTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	https://git.causal.agency/pounce/snapshot/

MAINTAINER=	june@causal.agency
COMMENT=	Multi-client IRC bouncer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 localbase:ldflags ssl
USE_RC_SUBR=	calico pounce

MAKE_ENV+=	MANDIR=${MANPREFIX}/man
CFLAGS+=	-D'OPENSSL_BIN=\"${OPENSSL_BIN}\"'

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base || ${SSL_DEFAULT} == openssl
LIB_DEPENDS+=	libtls.so:security/libretls
.endif

.if ${SSL_DEFAULT} == base
OPENSSL_BIN=/usr/bin/openssl
.else
OPENSSL_BIN=${LOCALBASE}/bin/openssl
.endif

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/calico
.for b in calico pounce
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${b}
.endfor

.include <bsd.port.post.mk>
