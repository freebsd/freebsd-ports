# New ports collection makefile for:	bsdconv
# Date created:				23 May 2009
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	6.2
CATEGORIES=	converters
MASTER_SITES=	https://github.com/buganini/${PORTNAME}/tarball/${PORTVERSION}/
DISTNAME=	buganini-${PORTNAME}-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	BSD licensed charset/encoding converter library

LICENSE=	BSD

GITVERSION=	50e0819
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/buganini-${PORTNAME}-${GITVERSION}

OPTIONS=	EXTRA "Extra codecs (Chinese specifics)" off

USE_LDCONFIG=	yes

MAKE_ARGS=	PREFIX=${PREFIX}

ALL_TARGET=	libbsdconv bsdconv_mktable meta bsdconv codecs_basic
INSTALL_TARGET=	installdir install_main install_basic

.include <bsd.port.options.mk>

.if defined(WITH_EXTRA)
ALL_TARGET+=	codecs_extra
INSTALL_TARGET+=install_extra
PLIST_SUB+=	EXTRA=""
.else
PLIST_SUB+=	EXTRA="@comment "
.endif

pre-install:
	${MKDIR} ${DATADIR}/ ${DATADIR}/from/ ${DATADIR}/inter/ ${DATADIR}/to/

.include <bsd.port.mk>
