# New ports collection makefile for:	libpar2
# Date created:				16 Aug 2008
# Whom:					Jeff Burchell <toxic@doobie.com>
#
# $FreeBSD$
#

PORTNAME=	libpar2
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	SF/parchive/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	toxic@doobie.com
COMMENT=	A library for manipulating par2 files, extracted from par2cmdline

LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

USE_LDCONFIG=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
