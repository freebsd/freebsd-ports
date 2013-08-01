# Created by: Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	autoconvert
PORTVERSION=	0.3.16
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intelligent Chinese encoding converter

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

MAKE_ENV=	CFLAG="${CPPFLAGS}" LIBS="${LDFLAGS}"
MAKE_ARGS=	CC=${CC}
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PROJECTHOST=	libhz

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS|#CFLAGS|" ${WRKSRC}/contrib/xchat-plugins/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ChangeLog Readme TODO Thanks Version ${DOCSDIR}/
.endif

.include <bsd.port.mk>
