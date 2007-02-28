# New ports collection makefile for:	updatedd
# Date created:		2003-12-02
# Whom:			geniusj@ods.org
#
# $FreeBSD$
#

PORTNAME=	updatedd
PORTVERSION=	2.6
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	geniusj@ods.org
COMMENT=	Dynamic DNS Update Client supporting multiple services

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		updatedd.1 updatedd-wrapper.1
MAN5=		updatedd-wrapper.conf.5

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-disable-portdocs
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/updatedd-wrapper.conf ]; then \
		${CP} -p ${PREFIX}/etc/updatedd-wrapper.conf.sample ${PREFIX}/etc/updatedd-wrapper.conf ; \
	fi

.include <bsd.port.mk>
