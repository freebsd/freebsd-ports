# New ports collection makefile for:	glademm
# Date created:		4th November 2003
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glademm
PORTVERSION=	2.6.0
CATEGORIES=	devel gnome
MASTER_SITES=	http://home.wtal.de/petig/Gtk/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	A C++ code generator backend for glade and glade2

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget
USE_LIBTOOL_VER=	15
USE_GETOPT_LONG=	yes

PLIST_FILES=	bin/glade-- bin/glademm-embed

.include <bsd.port.pre.mk>

post-patch:
	@${RM} -f ${WRKSRC}/src/getopt.*
	@${REINPLACE_CMD} \
		-Ee '/^@AMDEP/!s|getopt([^[:space:]])+||g' \
		-Ee '/^@AMDEP(.)+getopt/d' \
			${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} \
		-Ee 's|automake-([[:digit:]]+)\.([[:digit:]]+)|automake\1\2|g' \
		-e 's|autoconf2\.50|autoconf259|g' \
		-e 's|autoconf2\.13|autoconf213|g' \
			${WRKSRC}/src/glade--.cc \
			${WRKSRC}/src/Cxx.cc

.include <bsd.port.post.mk>
