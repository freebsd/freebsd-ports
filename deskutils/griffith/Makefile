# New ports collection makefile for:	griffith
# Date created:		27 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	griffith
PORTVERSION=	0.9.2
CATEGORIES=	deskutils
MASTER_SITES=	BERLIOS

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A film collection manager

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23 \
		${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml \
		py*-sqlalchemy>=0.3.3:${PORTSDIR}/databases/py-sqlalchemy

USE_PYTHON=	yes
USE_GNOME=	pygtk2 pygnomeextras
USE_GMAKE=	yes
NO_BUILD=	yes
MAN1=		${PORTNAME}.1
MANLANG=	"" pl pt

post-patch:
	@${FIND} ${WRKSRC}/ -name Makefile |\
		${XARGS} ${REINPLACE_CMD} -e '/^PREFIX/d' -e '/^MANDIR/s|=.*|=${MANPREFIX}/man|'
	@${REINPLACE_CMD} -e 's|/usr/share/fonts|${X11BASE}/lib/X11/fonts|' ${WRKSRC}/${PORTNAME}

.include <bsd.port.mk>
