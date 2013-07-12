# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	frontline
PORTVERSION=	0.5.4
PORTREVISION=	13
CATEGORIES=	graphics gnome
MASTER_SITES=	SF/autotrace/FrontLine/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An autotrace GUI FRONTend like streamLINE(TM)

LIB_DEPENDS=	autotrace.3:${PORTSDIR}/graphics/autotrace \
		popt.0:${PORTSDIR}/devel/popt

USE_GNOME=	gnomeprefix gnomehack gnomelibs imlib libartlgpl2
USES=		gettext gmake
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
