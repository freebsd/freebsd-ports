# New ports collection makefile for:	libpar2
# Date created:				16 Aug 2008
# Whom:					Jeff Burchell <toxic@doobie.com>
#
# $FreeBSD$
#

PORTNAME=	libpar2
PORTVERSION=	0.2
PORTREVISION=	3
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

OPTIONS=	ENABLECANCEL "Enable graceful cancellation of repairs" On

.include <bsd.port.pre.mk>

.if defined(WITH_ENABLECANCEL)
EXTRA_PATCHES+=	${FILESDIR}/xpatch-addcancel-par2repairer.cpp
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
