# ex:ts=8
# Ports collection makefile for:	gts
# Date created:			Jun 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gts
PORTVERSION=	0.7.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	erik@smluc.org
COMMENT=	GNU Triangulated Surface Library

USE_GNOME=	glib20 gnometarget pkgconfig
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

OPTIONS=	NETPBM "Build with libnetpbm support" off

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_NETPBM)
LIB_DEPENDS+=	netpbm.1:${PORTSDIR}/graphics/netpbm
PLIST_SUB=	NETPBM=""
.else
PLIST_SUB=	NETPBM="@comment "
.endif

post-extract:
.if !defined(WITH_NETPBM)
	@${REINPLACE_CMD} -e 's|netpbm="true"|netpbm="false"|' \
		${WRKSRC}/configure
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-release \$$(LT_RELEASE)||g ; s|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|'

.include <bsd.port.post.mk>
