PORTNAME=	bmk
DISTVERSION=	0.4
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Successor to make(1)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	realchonk
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/share/man
# kludge
CPP=

PLIST_FILES=	bin/mk \
		bin/mk-timings-summary \
		share/man/man1/mk.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mk

.include <bsd.port.mk>
