# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ixlib
PORTVERSION=	0.96.2
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small C++ tools library based on STL

USES=		gettext
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	${CFLAGS} -I${LOCALBASE}/include
MAKE_ENV+=	SED="sed"
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-configure:
	${CP} ${LTMAIN} ${WRKSRC}

.include <bsd.port.post.mk>
