# Created by: TAOKA Fumiyoshi <fmysh@iijmio-mail.jp>
# $FreeBSD$

PORTNAME=	pyshapelib
PORTVERSION=	0.3
CATEGORIES=	devel python geography
MASTER_SITES=	http://ftp.intevation.de/users/bh/pyshapelib/:py \
		http://dl.maptools.org/dl/shapelib/:c
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:py ${SHAPELIB}${EXTRACT_SUFX}:c

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	Python bindings for Shapelib

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

SHAPELIB=	shapelib-1.2.10
USE_LDCONFIG=	yes

PORTDOCS=	NEWS README
PORTEXAMPLES=	pytest.py

NO_STAGE=	yes
post-extract:
	${LN} -s ${WRKDIR}/${SHAPELIB} ${WRKDIR}/shapelib

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/$f ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
