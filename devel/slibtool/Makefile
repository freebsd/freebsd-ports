PORTNAME=	slibtool
PORTVERSION=	0.5.34
CATEGORIES=	devel
MASTER_SITES=	http://dl.midipix.org/${PORTNAME}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Skinny libtool implementation, written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.SLIBTOOL

HAS_CONFIGURE=	yes
USES=		tar:xz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/slibtool

.include <bsd.port.mk>
