# New ports collection makefile for:	py-sip
# Date created:		Tue Oct  8 09:51:22 SAST 2002
# Whom:			nbm
#
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	4.2
PORTREVISION=
CATEGORIES=	devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/sip/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lofi
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

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
		-e ${PYTHON_INCLUDEDIR} -v ${PREFIX}/share/sip )

post-install:
.if !defined(NOPORTDOCS)
	@( ${MKDIR} ${DOCSDIR} && cd ${WRKSRC}/doc && \
		${INSTALL_DATA} default.css sipref.html sipref.txt ${DOCSDIR} \
		&& ${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} )
.endif
	@${PYTHON_CMD} -c "import sipconfig"
	@${PYTHON_CMD} -O -c "import sipconfig"

.include <bsd.port.post.mk>
