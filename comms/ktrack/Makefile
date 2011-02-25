# New ports collection makefile for:	ktrack
# Date created:		22 February 2006
# Whom:			Diane Bruce <db@db.net>
#
# $FreeBSD$

PORTNAME=	ktrack
PORTVERSION=	0.3.0r1
PORTREVISION=	8
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.3.0-rc1
DISTNAME=	${PORTNAME}-0.3.0-rc1

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio satellite tracking and prediction

RUN_DEPENDS=	xplanet:${PORTSDIR}/astro/xplanet:install
LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib \
		jpeg:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_BZIP2=	yes
USE_KDEBASE_VER=3
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/HTML/en/ktrack
	${MKDIR} ${PREFIX}/share/doc/HTML/en/ktrack/common
	${INSTALL_MAN} ${WRKSRC}/doc/en/index.cache.bz2 ${PREFIX}/share/doc/HTML/en/ktrack/
	${INSTALL_MAN} ${WRKSRC}/doc/en/index.docbook ${PREFIX}/share/doc/HTML/en/ktrack/
.endif

.include <bsd.port.mk>
