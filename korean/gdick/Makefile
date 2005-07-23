# New ports collection makefile for:	ko-gdick
# Date created:		20 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdick
PORTVERSION=	0.9.1
PORTREVISION=	6
CATEGORIES=	korean python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gdick

MAINTAINER=	perky@FreeBSD.org
COMMENT=	English-Korean Dictionary Client for GNOME2

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/cjkcodecs.pth:${PORTSDIR}/converters/py-cjkcodecs

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehier pygnome2

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e \
		's,/usr/share/gdick/gdick.glade,${PREFIX}/share/gdick/gdick.glade,g' \
		${WRKSRC}/lib/gdick/gdick.py
	${REINPLACE_CMD} \
		-e 's,lib/bonobo,${X11BASE}/libdata/bonobo,g' \
		${WRKSRC}/setup.py
	${REINPLACE_CMD} -e 's,/usr/bin/gdick,${PREFIX}/bin/gdick,g' \
		${WRKSRC}/GNOME_GDick.server

.include <bsd.port.post.mk>
