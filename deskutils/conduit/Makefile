# New ports collection makefile for:	conduit
# Date created:		2006-10-10
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/conduit/Makefile,v 1.3 2006/10/11 20:26:26 ahze Exp $

PORTNAME=	conduit
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://files.conduit-project.org/releases/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Synchronization application for GNOME

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/goocanvasmodule.so:${PORTSDIR}/graphics/py-goocanvas \
		${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree \
		${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23 \
		xmlproc_parse:${PORTSDIR}/textproc/py-xml

NO_WRKSUBDIR=	yes
USE_PYTHON=	2.4+
MAKE_ENV=	DESTDIR=""
USE_GNOME=	pygnome2
DESKTOP_ENTRIES=	"Conduit" "${COMMENT}" "conduit-icon.png" \
			"${PORTNAME}" "GNOME;Application;Office;" true

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|; \
		s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR:S/${LOCALBASE}/${PREFIX}/}|' \
		${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${PREFIX}/share/applications

.include <bsd.port.post.mk>
