# New ports collection makefile for:	gview
# Version required:			0.1.12
# Date created:				30 April 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	gview-0.1.12
CATEGORIES=	graphics
MASTER_SITES=	http://gview.netpedia.net/ \
		http://homepages.petech.ac.za/~bruces/ \
		ftp://ftp.petech.ac.za/pub/viewers/ \
		http://www.geocities.com/ResearchTriangle/Facility/1468/sg/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	gdk_imlib.5:${PORTSDIR}/graphics/imlib \
		intl.1:${PORTSDIR}/devel/gettext

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/gview
.for file in AUTHORS BUGS COPYING ChangeLog NEWS README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gview
.endfor
.endif

.include <bsd.port.mk>
