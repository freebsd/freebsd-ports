PORTNAME=	got
DISTVERSION=	0.98
CATEGORIES=	devel
MASTER_SITES=	https://gameoftrees.org/releases/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Game of Trees version control system
WWW=		https://gameoftrees.org

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		localbase:ldflags uidfix

CONFLICTS_INSTALL=	p5-App-GitGot

# Insert #include "openbsd-compat.h" into each source file,
# after the <...> includes and before the "..." ones.
n=		${.newline}
post-extract:
	@${FIND} ${WRKSRC} -name '*.[cy]' -exec \
	    ${REINPLACE_CMD} '1,/^#include "/{ \
	    /^#include "/i\$n#include "openbsd-compat.h"\$n$n}' \
	    {} +
	${CP} -R ${FILESDIR}/openbsd-compat ${WRKSRC}

# The regression test suite requires:
#  installed got
#  installed git
#  installed perl and HTTP::Daemon
#  ssh to 127.0.0.1
regress:
	@(cd ${WRKSRC}/regress && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} regress)

.include <bsd.port.pre.mk>

# When using LibreSSL use its own libtls, but when using OpenSSL
# use libtls from libretls.
.if ${SSL_DEFAULT:Mlibressl*}
#	/* empty */
.else
LIB_DEPENDS+=	libtls.so:security/libretls
.endif # SSL_DEFAULT

.include <bsd.port.post.mk>
