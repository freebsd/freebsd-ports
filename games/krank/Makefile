# New Ports collection makefile for:	krank
# Date created:		2012-04-20
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	krank
PORTVERSION=	07
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Krank is a little casual game

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy

USE_BZIP2=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/krank \
		share/pixmaps/Krank.png

PORTDATA=	*
PORTDOCS=	CHANGELOG.txt README

post-patch:
	${REINPLACE_CMD} -e 's|`dirname.*|${DATADIR}|' ${WRKSRC}/krank

do-install:
# Wrapper script
	${INSTALL_SCRIPT} ${WRKSRC}/krank ${PREFIX}/bin

post-install:
# Data
.if !defined (NOPORTDATA)
	${MKDIR} ${DATADIR}
.  for d in art fonts html levels sounds src
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.  endfor
	${INSTALL_DATA} ${WRKSRC}/krank.iss ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/logo.xcf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/html/gfx/logo.png ${PREFIX}/share/pixmaps/Krank.png
.endif

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
