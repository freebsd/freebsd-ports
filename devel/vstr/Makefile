# Created by: Robert Schlotterbeck <robert@rs.tarrant.tx.us>
# $FreeBSD$

PORTNAME=	vstr
PORTVERSION=	1.0.15
CATEGORIES=	devel
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://sce-tindy.tecnik93.com/FreeBSD/others_ports/${PORTNAME}/ \
		http://www.and.org/vstr/1.0.15/ \
		http://www.and.org/vstr/latest/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose string library for C

OPTIONS_DEFINE=	DOCS

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_CSTD=	gnu89
USES=	gmake pathfix pkgconfig
USE_LDCONFIG=	yes

post-install:
	cd ${WRKSRC}/Documentation && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_fLAGS} ${MAKEFILE} ${MAKE_ARGS} install-man3

regression-test:
	(cd ${WRKSRC} &&	\
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
