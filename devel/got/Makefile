# $FreeBSD$

PORTNAME=	got
PORTVERSION=	0.43
CATEGORIES=	devel
MASTER_SITES=	https://gameoftrees.org/releases/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Game of Trees version control system

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		uidfix

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
#  ssh to 127.0.0.1
run-test:
	@(cd ${WRKSRC}/regress && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} regress)

.include <bsd.port.mk>
