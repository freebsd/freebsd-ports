# New ports collection makefile for:	griffith
# Date created:		27 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	griffith
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight film collection manager

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23 \
		${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml \
		${PYTHON_PKGNAMEPREFIX}chardet>=1.0.1:${PORTSDIR}/textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.4.8:${PORTSDIR}/databases/py-sqlalchemy

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_GNOME=	pygtk2 pygnomeextras
USE_GMAKE=	yes
NO_BUILD=	yes
MAN1=		${PORTNAME}.1
MANLANG=	"" pl pt

post-patch:
	@${FIND} ${WRKSRC}/ -name Makefile |\
		${XARGS} ${REINPLACE_CMD} -e '/^PREFIX/d' -e '/^MANDIR/s|=.*|=${MANPREFIX}/man|'
	@${REINPLACE_CMD} -e '/^LANGUAGES=/s|find.*|cd i18n/\&\&ls -d *)|' ${WRKSRC}/Makefile
#	@${REINPLACE_CMD} -e 's|/usr/share/fonts|${LOCALBASE}/lib/X11/fonts|' ${WRKSRC}/${PORTNAME}

.include <bsd.port.mk>
