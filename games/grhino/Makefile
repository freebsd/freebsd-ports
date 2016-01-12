# Created by: UMENO Takashi <umeno@rr.iij4u.or.jp>
# $FreeBSD$

PORTNAME=	grhino
PORTVERSION=	0.16.1
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	SF/rhino/GRhino/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GRhino Othello/Reversi Program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext pkgconfig perl5
USE_GNOME=	gnomeprefix libgnomeui
USE_PERL5=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_OMF=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
