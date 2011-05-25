# New ports collection makefile for:    bug5
# Date created:                         25 April 2011
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bug5
PORTVERSION=	1.4
CATEGORIES=	chinese converters
MASTER_SITES=	https://github.com/buganini/${PORTNAME}/tarball/${PORTVERSION}/
DISTNAME=	buganini-${PORTNAME}-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	A Big5 <-> UTF-8 translating layer in terminal

LICENSE=	BSD

GITVERSION=	14af387
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/buganini-${PORTNAME}-${GITVERSION}

LIB_DEPENDS=	bsdconv.5:${PORTSDIR}/converters/bsdconv

PLIST_FILES=	bin/bug5

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bug5 ${PREFIX}/bin/

.include <bsd.port.mk>
