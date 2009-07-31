# New ports collection makefile for:   soundconverter
# Date created:        04 September 2007
# Whom:                Jona Joachim <jaj@hcl-club.lu>
#
# $FreeBSD$
#

PORTNAME=	soundconverter
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	BERLIOS
#MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The sound conversion application for the GNOME environment

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gst-0.10/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer

USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GNOME=	pygtk2 pygnome2

MAKE_ENV=	MAKE=${LOCALBASE}/bin/gmake

INSTALLS_ICONS=	yes
MAN1=	soundconverter.1

post-patch:
	@${REINPLACE_CMD} -e 's|@GMSGFMT@|${LOCALBASE}/bin/msgfmt|' ${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's|#!/usr/bin/python|#!/usr/bin/env python|' ${WRKSRC}/src/soundconverter.py

.include <bsd.port.mk>
