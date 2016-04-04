# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	libmimedir
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for parsing RFC2425 MIME Directory Profile information

USES=		desthack libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC=byacc
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=yes

post-patch:
	${REINPLACE_CMD} -e 's/444/644/g' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmimedir.so

regression-test:
	cd ${WRKSRC} && ./test

.include <bsd.port.mk>
