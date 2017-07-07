# $FreeBSD$

PORTNAME=	dub
PORTVERSION=	1.3.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Package and build manager for D applications and libraries

BUILD_DEPENDS=	ldmd2:lang/ldc
LIB_DEPENDS=	libcurl.so:ftp/curl

LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	dlang

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR}/LICENSE

post-patch:
	${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${WRKSRC}/source/dub/version_.d

do-build:
	@cd ${WRKSRC} && ${SH} build.sh

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${STAGEDIR}/${DATADIR}/LICENSE

.include <bsd.port.mk>
