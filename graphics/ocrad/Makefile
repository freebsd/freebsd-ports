# New ports collection makefile for:	graphics/ocrad
# Date created:				12.11.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	ocrad
PORTVERSION=	0.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	q@uni.de
COMMENT=	OCR program implemented as filter

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GETOPT_LONG=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

DOCS=		AUTHORS ChangeLog NEWS README TODO
INFO=		ocrad

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
