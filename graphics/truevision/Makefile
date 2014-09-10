# Created by: ijliao
# $FreeBSD$

PORTNAME=	truevision
PORTVERSION=	0.5.5.2
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20sources/0.5.5
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME 3D modeler

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:bzip2
USE_GNOME=	gnomeprefix intlhack libgnomeui
USE_GL=		gl
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	$$(pkg-config --cflags gtkglext-1.0) \
		-I${LOCALBASE}/include
LIBS+=		$$(pkg-config --libs gtkglext-1.0) \
		-L${LOCALBASE}/lib -lz

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS=""||g ; \
		 s|-I/usr/include/gtkglext-1.0/||g ; \
		 s|-I/usr/local/include/gtkglext-1.0/||g ; \
		 s|-I/usr/lib/gtkglext-1.0/include/||g ; \
		 s|-I/usr/local/lib/gtkglext-1.0/include/||g ; \
		 s|-I/usr/local/include ||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-I/usr/include||g ; \
		 s|-I/usr/local/include||g ; \
		 s|-I/usr/X11R6/include||g ; \
		 s|-L/usr/lib||g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-L/usr/X11R6/lib||g ; \
		 s|-O2||g ; \
		 s|^truevisiondoc|#truevisiondoc|g ; \
		 /update-mime-database/s|^|#|'

.include <bsd.port.mk>
