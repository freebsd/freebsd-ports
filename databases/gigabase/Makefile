# ports collection makefile for:	gigabase
# Date created:			15 August 2000
# Whom:				Sergey A. Osokin <osa@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	gigabase
PORTVERSION=	3.70
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Object-Relational Database Management System

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 601103
	@${REINPLACE_CMD} -e \
		'/GETHOSTBYNAME_R/s|^#define|// #define|g' ${WRKSRC}/config.h
.endif

.include <bsd.port.post.mk>
