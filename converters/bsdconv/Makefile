# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	bsdconv
PORTVERSION=	9.0
CATEGORIES=	converters
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	BSD licensed charset/encoding converter library

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_COMMIT=	b514ea8

OPTIONS_DEFINE=	EXTRA
EXTRA_DESC=	Extra codecs (Chinese specifics)

USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes
MAKE_ARGS=	PREFIX=${PREFIX}

ALL_TARGET=	libbsdconv bsdconv_mktable meta bsdconv codecs_basic
INSTALL_TARGET=	installdir install_main install_basic

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXTRA}
ALL_TARGET+=	codecs_extra
INSTALL_TARGET+=install_extra
PLIST_SUB+=	EXTRA=""
.else
PLIST_SUB+=	EXTRA="@comment "
.endif

pre-install:
	${MKDIR} ${DATADIR}/ ${DATADIR}/from/ ${DATADIR}/inter/ ${DATADIR}/to/

.include <bsd.port.mk>
