# New ports collection makefile for:	fyre
# Date created:				2004 11 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fyre
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://flapjack.navi.cx/releases/fyre/

MAINTAINER=	samy@kerneled.org
COMMENT=	Chaos map rendering system with GTK+-2 interface

LIB_DEPENDS=	Half:${PORTSDIR}/graphics/OpenEXR \
		gnet-2.0:${PORTSDIR}/net/gnet2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	libglade2
USE_GETOPT_LONG=yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
.if defined(WITH_OPTIMIZED_CFLAGS)
CPPFLAGS+=	-march=i686 -O3 -ffast-math \
		-fomit-frame-pointer -D__NO_INLINE__
.else
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The following options are available:"
	@${ECHO_CMD} "  WITH_OPTIMIZED_CFLAGS    - build port with optimization support"
	@${ECHO_CMD} ""
.endif
.endif

# check for update-desktop-database should go here
PLIST_SUB+=	WITH_FDO="@comment "

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
