# New ports collection makefile for:	ko-gdick
# Date created:		20 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdick
PORTVERSION=	0.6.1
CATEGORIES=	korean python
MASTER_SITES=	http://ddt.mirstyle.org/data/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	English-Korean Dictionary Client for GNOME2

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/gtk-2.0/atk.so:${PORTSDIR}/x11-toolkits/py-gtk2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_BZIP2=	yes

.if defined(WITH_GNOME)
USE_GNOME=	gnomehier
RUN_DEPENDS+=	${PYTHONPREFIX_SITELIBDIR}/gtk-2.0/gconfmodule.so:${PORTSDIR}/x11-toolkits/py-gnome2
PLIST_SUB=	GNOMEONLY=""
.else
PLIST_SUB=	GNOMEONLY="@comment "
.endif

post-extract:
	${INSTALL_DATA} ${FILESDIR}/setup.py ${WRKSRC}

post-patch:
.for f in gdick gdick_applet
	${SED} -e 's,/usr/bin/gdick.glade,${PREFIX}/share/gdick/gdick.glade,g' \
		${WRKSRC}/$f.py > ${WRKSRC}/$f
.endfor

post-install:
.if defined(WITH_GNOME)
	${INSTALL_DATA} ${WRKSRC}/GNOME_GDick.server ${X11BASE}/libdata/bonobo/servers/
.endif

.include <bsd.port.mk>
