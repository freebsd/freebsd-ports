# Created by: ijliao
# $FreeBSD$

PORTNAME=	libdbi
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Database Independent Abstraction Layer for C

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|-O20|${CFLAGS}|g" -e "s|-std=gnu99||g" \
		 ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/driver-guide
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/programmers-guide
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/driver-guide/*.html \
		${STAGEDIR}${DOCSDIR}/driver-guide
	${INSTALL_DATA} ${WRKSRC}/doc/programmers-guide/*.html \
		${STAGEDIR}${DOCSDIR}/programmers-guide

.include <bsd.port.mk>
