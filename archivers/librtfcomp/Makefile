# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	librtfcomp
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	SF/synce/SynCE/${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for handling compressed RTF documents

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		libtool

CONFIGURE_ARGS=	--disable-python-bindings
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tests/fromrtf ${STAGEDIR}${PREFIX}/bin/fromrtf
	${INSTALL_SCRIPT} ${WRKSRC}/tests/test ${STAGEDIR}${PREFIX}/bin/testrtf
	${INSTALL_SCRIPT} ${WRKSRC}/tests/tortf ${STAGEDIR}${PREFIX}/bin/tortf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librtfcomp.so.0.0.0

.include <bsd.port.mk>
