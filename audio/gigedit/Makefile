# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gigedit
PORTVERSION=	0.2.0
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Instrument editor for gig files

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	libgig.so:${PORTSDIR}/audio/libgig \
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	${LOCALBASE}/lib/linuxsampler/liblinuxsampler.so.3:${PORTSDIR}/audio/linuxsampler
BUILD_DEPENDS:=	${RUN_DEPENDS}

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lsigc-2.0
USES=		gettext gmake pkgconfig libtool
USE_LDCONFIG=	yes
USE_GNOME=	intltool
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
