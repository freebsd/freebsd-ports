PORTNAME=	nss_resinit
PORTVERSION=	20060412
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.mahoroba.org/~ume/FreeBSD/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Resolver re-initialization NSS module

LICENSE=	BSD2CLAUSE

USES=		uidfix
MAKE_ARGS=	MANDIR=${PREFIX}/share/man/man

PLIST_FILES=	lib/nss_resinit.so lib/nss_resinit.so.1 \
		share/man/man8/nss_resinit.8.gz

.include <bsd.port.pre.mk>

.if defined(WITH_COMPAT5X)
BROKEN=		7.X and later do not have compat syms for the old resolver
MAKE_ARGS+=	CC="${CC} -DWITH_COMPAT5X"
.endif

.include <bsd.port.post.mk>
