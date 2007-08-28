# New ports collection makefile for:	ETL
# Date created:				25 Jun 2006
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	etl
DISTVERSION=	0.04.09
CATEGORIES=	devel lang
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	synfig
DISTNAME=	ETL-${DISTVERSION}

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	Voria Extended Class and Template Library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
