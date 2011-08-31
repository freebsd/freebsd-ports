# New ports collection makefile for:	ko-gdick
# Date created:		20 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdick
PORTVERSION=	0.9.2
CATEGORIES=	korean python
MASTER_SITES=	http://kldp.net/frs/download.php/816/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English-Korean Dictionary Client for GNOME2

IGNORE=		has multiple run-time problems, e. g., using obsolete URLs
DEPRECATED=	HTMLs from the recent Yahoo! Korea Dictionary cannot be parsed
EXPIRATION_DATE=2011-11-01

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/cjkcodecs.pth:${PORTSDIR}/converters/py-cjkcodecs

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_BZIP2=	yes
USE_GNOME=	gnomehier pygnome2

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e \
		's,/usr/share/gdick/gdick.glade,${PREFIX}/share/gdick/gdick.glade,g' \
		${WRKSRC}/lib/gdick/gdick.py
	${REINPLACE_CMD} \
		-e 's,lib/bonobo,${LOCALBASE}/libdata/bonobo,g' \
		${WRKSRC}/setup.py
	${REINPLACE_CMD} -e 's,/usr/bin/gdick,${PREFIX}/bin/gdick,g' \
		${WRKSRC}/GNOME_GDick.server

.include <bsd.port.post.mk>
