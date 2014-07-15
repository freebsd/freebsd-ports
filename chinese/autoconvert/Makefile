# Created by: Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	autoconvert
PORTVERSION=	0.3.16
PORTREVISION=	4
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	libhz
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intelligent Chinese encoding converter

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's/CFLAG/CFLAGS/' -e 's/make/$$(MAKE)/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/gcc/${CC}/' -e 's/LIBS=/&${LDFLAGS} /' \
		-e 's/CFLAGS=/&${CPPFLAGS} ${CFLAGS} /' \
		${WRKSRC}/Makefile ${WRKSRC}/hzconvert/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ChangeLog Readme TODO Thanks Version ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
