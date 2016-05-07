# $FreeBSD$

PORTNAME=	wrapsrv
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	DNS SRV record command line wrapper

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	docbook2mdoc:textproc/docbook2mdoc

PLIST_FILES=	bin/wrapsrv man/man1/wrapsrv.1.gz

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/wrapsrv

.include <bsd.port.mk>
