# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	libmimedir
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for parsing RFC2425 MIME Directory Profile information

USES=		bison desthack libtool:keepla
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=yes

post-patch:
	${REINPLACE_CMD} -e 's/444/644/g' ${WRKSRC}/Makefile.in

regression-test:
	cd ${WRKSRC} && ./test

.include <bsd.port.mk>
