# New ports collection makefile for:	openag
# Date created:				09 April 2002
# Whom:	janos.mohacsi@bsd.hu and jon@phuq.co.uk
#
# $FreeBSD$

PORTNAME=	openag
PORTVERSION=	1.1.1
PORTREVISION=1
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openags
DISTNAME=	OpenAG-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu

BROKEN=		The AudioGalaxy Search Server shutdown in June 2002

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}
CONFIGURE_ENV=	WGET="fetch" \
		WGET_FLAGS="-o"

DOC_FILES=	AUTHORS COPYING ChangeLog INSTALL README

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
