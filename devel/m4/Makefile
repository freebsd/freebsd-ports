# New ports collection makefile for:	m4
# Date created:		25 October 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	m4
PORTVERSION=	1.4.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	m4

MAINTAINER=	ade@FreeBSD.org
COMMENT=	GNU m4

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--infodir=${PREFIX}/info --mandir=${PREFIX}/man \
		--program-prefix=g

.if defined(WITH_CHANGEWORD)
CONFIGURE_ARGS+=	--enable-changeword
.endif

INFO=	m4
MAN1=	gm4.1

EXAMPLESDIR=	share/examples/gm4

post-install:
	@${MKDIR} ${PREFIX}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${PREFIX}/${EXAMPLESDIR}

.include <bsd.port.mk>
