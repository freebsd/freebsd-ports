# New ports collection makefile for:	eric
# Date created:				20 January 2004
# Whom:					leafy <leafy@leafy.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	eric
PORTVERSION=	3.8.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	eric-ide

MAINTAINER=	leafy7382@gmail.com
COMMENT=	A Python IDE implemented using PyQt and QScintilla

BUILD_DEPENDS=	${X11BASE}/lib/libqscintilla.so:${PORTSDIR}/x11-toolkits/qscintilla \
		${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip \
		pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/eric3 bin/eric3-api bin/eric3-doc bin/eric3-helpviewer \
		bin/eric3-qregexp bin/eric3-re bin/eric3-trpreviewer \
		bin/eric3-uipreviewer bin/eric3-unittest \
		%%PYTHON_SITELIBDIR%%/sitecustomize.pyc \
		%%PYTHON_SITELIBDIR%%/sitecustomize.py \
		%%PYTHON_SITELIBDIR%%/eric3config.py
PLISTDIR=	${PYTHON_SITELIBDIR}/eric3

.include <bsd.port.pre.mk>

do-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} install.py -b ${PREFIX}/bin/ \
		-d ${PYTHONPREFIX_SITELIBDIR} )

post-install:
.for dir in ${PLISTDIR}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
