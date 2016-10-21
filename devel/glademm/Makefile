# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glademm
PORTVERSION=	2.6.0
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	http://home.wtal.de/petig/Gtk/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ code generator backend for glade and glade2

USES=		gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/glade-- bin/glademm-embed

.include <bsd.port.pre.mk>

post-patch:
	@${RM} ${WRKSRC}/src/getopt.*
	@${REINPLACE_CMD} \
		-Ee '/^@AMDEP/!s|getopt([^[:space:]])+||g' \
		-Ee '/^@AMDEP(.)+getopt/d' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
