# New ports collection makefile for:	ko-gdick
# Date created:		20 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdick
PORTVERSION=	0.6.2
CATEGORIES=	korean python
MASTER_SITES=	http://ddt.mirstyle.org/data/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	English-Korean Dictionary Client for GNOME2

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/gtk-2.0/atk.so:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHONPREFIX_SITELIBDIR}/cjkcodecs.pth:${PORTSDIR}/converters/py-cjkcodecs

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes
USE_BZIP2=	yes
PLIST_SUB=	${OPTPLIST_SUB}

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME)
USE_GNOME=	gnomehier
RUN_DEPENDS+=	${PYTHONPREFIX_SITELIBDIR}/gtk-2.0/gconfmodule.so:${PORTSDIR}/x11-toolkits/py-gnome2
OPTPLIST_SUB=	GNOMEONLY=""
PYDISTUTILS_INSTALLARGS+=	--bonobo-dir="${X11BASE}/libdata/bonobo"
.else
OPTPLIST_SUB=	GNOMEONLY="@comment "
PYDISTUTILS_INSTALLARGS+=	--without-gnome
.endif

post-patch:
.for f in gdick.py gdick_applet
	${REINPLACE_CMD} -e \
		's,/usr/share/gdick/gdick.glade,${PREFIX}/share/gdick/gdick.glade,g' \
		${WRKSRC}/$f
.endfor
	${REINPLACE_CMD} -e 's,/usr/bin/gdick,${PREFIX}/bin/gdick,g' \
		${WRKSRC}/GNOME_GDick.server
	${REINPLACE_CMD} -e 's,(sys\.argv),("--without-gnome"),g' \
		${WRKSRC}/setup.py

.include <bsd.port.post.mk>
