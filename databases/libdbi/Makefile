# Created by: ijliao
# $FreeBSD$

PORTNAME=	libdbi
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Database Independent Abstraction Layer for C

USES=		pathfix
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-O20|${CFLAGS}|g" -e "s|-std=gnu99||g" \
		 ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/driver-guide
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/programmers-guide
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/driver-guide/*.html \
		${STAGEDIR}${DOCSDIR}/driver-guide
	${INSTALL_DATA} ${WRKSRC}/doc/programmers-guide/*.html \
		${STAGEDIR}${DOCSDIR}/programmers-guide

.include <bsd.port.mk>
