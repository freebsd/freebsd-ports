# New ports collection makefile for:   soundconverter
# Date created:        04 September 2007
# Whom:                Jona Joachim <jaj@hcl-club.lu>
#
# $FreeBSD$
#

PORTNAME=	soundconverter
PORTVERSION=	1.4.4
PORTREVISION=	4
CATEGORIES=	audio python
MASTER_SITES=	BERLIOS

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	The sound conversion application for the GNOME environment

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gst-0.10/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GNOME=	pygtk2 pygnome2

MAKE_ENV=	MAKE=${LOCALBASE}/bin/gmake

INSTALLS_ICONS=	yes
MAN1=	soundconverter.1

post-patch:
	@${REINPLACE_CMD} -e 's|@GMSGFMT@|${LOCALBASE}/bin/msgfmt|; \
		s|itlocaledir = .*|itlocaledir = ${LOCALBASE}/share/locale|g' \
			${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's|#!/usr/bin/python|#!/usr/bin/env python|' ${WRKSRC}/src/soundconverter.py

.include <bsd.port.mk>
