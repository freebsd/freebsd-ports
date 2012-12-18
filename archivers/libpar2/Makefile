# Created by: Jeff Burchell <toxic@doobie.com>
# $FreeBSD$

PORTNAME=	libpar2
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	SF/parchive/${PORTNAME}/${PORTVERSION}

MAINTAINER=	toxic@doobie.com
COMMENT=	Library for manipulating PAR2 files, extracted from par2cmdline

LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20

GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ENABLECANCEL
OPTIONS_DEFAULT=	ENABLECANCEL
ENABLECANCEL_DESC=	Enable graceful cancellation of repairs

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MENABLECANCEL}
EXTRA_PATCHES=	${FILESDIR}/xpatch-addcancel-par2repairer.cpp
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
