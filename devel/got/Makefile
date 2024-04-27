PORTNAME=	got
DISTVERSION=	0.98.2
CATEGORIES=	devel
MASTER_SITES=	https://gameoftrees.org/releases/portable/
DISTNAME=	got-portable-${DISTVERSION}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Game of Trees version control system
WWW=		https://gameoftrees.org

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		localbase pkgconfig ssl

CONFLICTS_INSTALL=	p5-App-GitGot

GNU_CONFIGURE=	Yes

.include <bsd.port.pre.mk>

# When using LibreSSL use its own libtls, but when using OpenSSL
# use libtls from libretls.
.if ${SSL_DEFAULT:Mlibressl*}
#	/* empty */
.else
LIB_DEPENDS+=	libtls.so:security/libretls
.endif # SSL_DEFAULT

.include <bsd.port.post.mk>
