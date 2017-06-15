# Created by: ijliao
# $FreeBSD$

PORTNAME=	truevision
DISTVERSION=	0.5.5-2
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20sources/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME 3D modeler

LICENSE=	GPLv2+

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		python shared-mime-info tar:bzip2
USE_GNOME=	gnomeprefix intlhack libgnomeui
USE_GL=		gl
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
