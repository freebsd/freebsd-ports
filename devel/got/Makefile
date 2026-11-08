PORTNAME=	got
DISTVERSION=	0.130.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://gameoftrees.org/releases/portable/
DISTNAME=	got-portable-${DISTVERSION}

PATCH_SITES=	https://github.com/gameoftrees/got-portable/commit/
PATCHFILES=	3fb2130a1acdb6b75c8c39c903f845c49d835a2bed1f53efea0675903367e589.patch:-p1 \
		9f36809872a2f83a341568b0c94a0506dc75c6ad0f7abc5f1363b7fc9da3bb77.patch:-p1

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Game of Trees version control system
WWW=		https://gameoftrees.org

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		localbase pkgconfig ssl

CONFLICTS_INSTALL=	p5-App-GitGot

GNU_CONFIGURE=	Yes

# The regression test suite requires:
#  installed got
#  installed git
#  installed perl and HTTP::Daemon
#  ssh to 127.0.0.1
tests:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} tests)

.include <bsd.port.pre.mk>

# When using LibreSSL use its own libtls, but when using OpenSSL
# use libtls from libretls.
.if ${SSL_DEFAULT:Mlibressl*}
#	/* empty */
.else
LIB_DEPENDS+=	libtls.so:security/libretls
.endif # SSL_DEFAULT

.include <bsd.port.post.mk>
