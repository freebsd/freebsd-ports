# New ports collection makefile for:	accerciser
# Date created:		2007-09-17
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/accerciser/Makefile,v 1.36 2010/04/27 21:38:19 kwm Exp $
#

PORTNAME=	accerciser
PORTVERSION=	1.10.1
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interactive Python accessibility explorer for GNOME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pygnomedesktop atspi intlhack
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_DISPLAY=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	accerciser.schemas
MAN1=		accerciser.1

.if !defined(DISPLAY)
pre-configure:
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
	    ${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
	    ${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
	@${LOCALBASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5

post-configure:
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
	    ${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
	    ${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
.endif

.include <bsd.port.mk>
