# New ports collection makefile for:	zonecheck
# Date created:		10 July 2003
# Whom:	      		Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	zonecheck
PORTVERSION=	2.0.0b9
CATEGORIES=	dns ipv6 ruby
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/src
EXTRACT_SUFX=	.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Perform consistency checks on DNS zones

.if defined(WITH_X11)
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
.endif

USE_GMAKE=	yes
USE_RUBY=	yes
RUBY_VER=	1.8
USE_RUBY_FEATURES=	ruby18

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		zonecheck.1
DOCS=		BUGS INSTALL README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
