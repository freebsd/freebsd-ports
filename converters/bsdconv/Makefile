# New ports collection makefile for:	bsdconv
# Date created:				23 May 2009
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	7.5
CATEGORIES=	converters
MASTER_SITES=	https://github.com/buganini/${PORTNAME}/tarball/${PORTVERSION}/
DISTNAME=	buganini-${PORTNAME}-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	BSD licensed charset/encoding converter library

LICENSE=	BSD

GITVERSION=	cf1989b
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/buganini-${PORTNAME}-${GITVERSION}

OPTIONS_DEFINE=	EXTRA
EXTRA_DESC=	Extra codecs (Chinese specifics)

USE_LDCONFIG=	yes

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
