# New ports collection makefile for:	py-sip
# Date created:		Tue Oct  8 09:51:22 SAST 2002
# Whom:			nbm
#
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	4.2.1
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/sip/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sip-snapshot-20050709

MAINTAINER=	danny@ricin.com
COMMENT=	Python to C and C++ bindings generator

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_PYTHON=	yes
USE_QT_VER=	3

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

.include <bsd.port.pre.mk>

do-configure:
	@( cd ${WRKSRC} && ${SETENV} QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		${PYTHON_CMD} configure.py \
		-b ${PREFIX}/bin -d ${PYTHONPREFIX_SITELIBDIR} \
		-e ${PYTHON_INCLUDEDIR} -v ${DATADIR} )

post-install:
.if !defined(NOPORTDOCS)
	@( ${MKDIR} ${DOCSDIR} && cd ${WRKSRC} && ${INSTALL_DATA} \
		doc/default.css doc/sipref.txt NEWS LICENSE ${DOCSDIR} && \
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} )
.endif
	@# pyqt/pykde use this
	@${MKDIR} ${DATADIR}
	@${PYTHON_CMD} -c "import sipconfig"
	@${PYTHON_CMD} -O -c "import sipconfig"

.include <bsd.port.post.mk>
