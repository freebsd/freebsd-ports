# New ports collection makefile for:	glademm
# Date created:		4th November 2003
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glademm
PORTVERSION=	2.0.0.1
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	http://home.wtal.de/petig/Gtk/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	A C++ code generator backend for glade and glade2

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget
USE_LIBTOOL=	yes
USE_GETOPT_LONG=	yes

.include <bsd.port.pre.mk>

post-patch:
	${RM} -f ${WRKSRC}/src/getopt.*
	@${REINPLACE_CMD} \
		-e 's|automake-1.7|automake17|g' \
		-e 's|automake-1.5|automake15|g' \
		-e 's|automake-1.4|automake14|g' \
		-e 's|autoconf2.50|autoconf257|g' \
		-e 's|autoconf2.13|autoconf213|g' \
		${WRKSRC}/src/glade--.cc

.include <bsd.port.post.mk>
