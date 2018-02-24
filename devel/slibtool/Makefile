# $FreeBSD$

PORTNAME=	slibtool
PORTVERSION=	0.5.18
CATEGORIES=	devel
MASTER_SITES=	http://dl.midipix.org/${PORTNAME}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Skinny libtool implementation, written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.SLIBTOOL

HAS_CONFIGURE=	yes
USES=		gmake tar:xz

post-patch:
	${REINPLACE_CMD} -e "s/make/${MAKE_CMD}/g" ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/slibtool

.include <bsd.port.mk>
