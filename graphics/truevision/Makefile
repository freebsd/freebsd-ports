# ex:ts=8
# Ports collection makefile for:	truevision
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	truevision
PORTVERSION=	0.5.5.2
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNOME 3D modeler

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui
USE_GL=		gl
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		truevision.1

CPPFLAGS=	-I${LOCALBASE}/include \
		`pkg-config --cflags gtkglext-1.0`
LDFLAGS=	-L${LOCALBASE}/lib \
		`pkg-config --libs gtkglext-1.0`

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
		 s|^truevisiondoc|#truevisiondoc|g'

.include <bsd.port.mk>
