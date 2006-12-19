# New ports collection makefile for:	exaile
# Date created:		19 December 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exaile
DISTVERSION=	0.2.7b2
CATEGORIES=	audio
MASTER_SITES=	http://www.exaile.org/files/ CSME
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	AmaroK replacement for GTK+

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23

USE_GNOME=	pygtk2
USE_GSTREAMER=	python
USE_PYTHON=	yes
PLIST_FILES=	share/applications/${PORTNAME}.desktop share/pixmaps/${PORTNAME}.png bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/^PREFIX/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^PYTHON_DIR/s|=.*|=${PYTHON_INCLUDEDIR}|' ${WRKSRC}/mmkeys/Makefile

create-plist:
	${FIND} -s ${DATADIR} -not -type d|${SED} -e 's|^${DATADIR}|%%DATADIR%%|' > ${PLIST}
	${FIND} -ds ${DATADIR} -type d|${SED} -e 's|^${DATADIR}|%%DATADIR%%|' \
		-e 's|^|@dirrm |' >> ${PLIST}
	@${ECHO_CMD} '@dirrmtry share/applications' >> ${PLIST}
	@${ECHO_CMD} '@dirrmtry share/pixmaps' >> ${PLIST}

.include <bsd.port.mk>
