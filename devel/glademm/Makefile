# New ports collection makefile for:	glademm
# Date created:		4th November 2003
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glademm
PORTVERSION=	2.6.0
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	http://home.wtal.de/petig/Gtk/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	A C++ code generator backend for glade and glade2

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/glade-- bin/glademm-embed

.include <bsd.port.pre.mk>

post-patch:
	@${RM} -f ${WRKSRC}/src/getopt.*
	@${REINPLACE_CMD} \
		-Ee '/^@AMDEP/!s|getopt([^[:space:]])+||g' \
		-Ee '/^@AMDEP(.)+getopt/d' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
