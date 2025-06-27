PORTNAME=	slibtool
PORTVERSION=	0.7.3
CATEGORIES=	devel
MASTER_SITES=	http://dl.midipix.org/${PORTNAME}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Skinny libtool implementation, written in C
WWW=		https://git.foss21.org/slibtool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.SLIBTOOL

HAS_CONFIGURE=	yes
USES=		tar:xz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/slibtool

.include <bsd.port.mk>
