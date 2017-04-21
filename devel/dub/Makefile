# $FreeBSD$

PORTNAME=	dub
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/dlang/dub/archive/
DISTFILES=	v${PORTVERSION}.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Package and build manager for D applications and libraries

BUILD_DEPENDS=	ldmd2:lang/ldc
LIB_DEPENDS=	libcurl.so:ftp/curl

LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/LICENSE

post-patch:
	${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${WRKSRC}/source/dub/version_.d

do-build:
	@cd ${WRKSRC} && ${SH} build.sh

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${STAGEDIR}/${DATADIR}/LICENSE

.include <bsd.port.mk>
