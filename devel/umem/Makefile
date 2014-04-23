# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	umem
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://labs.omniti.com/portableumem/releases/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of the Solaris memory allocator

USES=		libtool:keepla
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386 amd64
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/ -ldl//g' ${WRKSRC}/Makefile.in

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
