# New ports collection makefile for:	kdissert
# Date created:				2004 06 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdissert
PORTVERSION=	1.0.3.4
CATEGORIES=	deskutils kde
MASTER_SITES=	http://www.kde-apps.org/content/files/
DISTNAME=	12725-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE mindmapping tool

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's:%%CXX%%:${CXX}:g ; \
		 s:%%CXXFLAGS%%:${CXXFLAGS} ${PTHREAD_CFLAGS}:g ; \
		 s:%%LINKFLAGS%%:${PTHREAD_LIBS}:g' ${WRKSRC}/SConstruct

do-configure:
	@cd ${WRKSRC} && ${SETENV} PREFIX="${PREFIX}" \
		QTDIR="${QT_PREFIX}" KDEDIR="${KDE_PREFIX}" scons configure

do-build:
	@cd ${WRKSRC} && scons

do-install:
	@cd ${WRKSRC} && scons install
	@${STRIP_CMD} ${PREFIX}/bin/kdissert

.include <bsd.port.mk>
