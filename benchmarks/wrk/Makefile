# New ports collection makefile for:	wrk
# Date created:				01 Aug 2012
# Whom:					Sergey A. Osokin <osa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wrk
PORTVERSION=	1.0.0
CATEGORIES=	benchmarks www
MASTER_SITES=	http://github.com/wg/${PORTNAME}/tarball/master/
DISTNAME=	${PORTNAME}-${PORTVERSION}-${GITVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	The modern HTTP benchmarking tool

LICENSE=	AL2

FETCH_ARGS=	-pRr
GITVERSION=	0-g6d143f1
WRKSRC=		${WRKDIR}/wg-${PORTNAME}-${GITVERSION:S/^0-g//}
USE_GMAKE=	yes
CFLAGS+=	-std=c99 -D_DECLARE_C99_LDBL_MATH

PLIST_FILES=	bin/wrk

post-patch:
	@${REINPLACE_CMD} '1d' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
