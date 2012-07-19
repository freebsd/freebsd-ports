# New Ports collection makefile for:	Pycadia
# Date created:		2012-05-09
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	pycadia
PORTVERSION=	0.5.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GENTOO:S/%SUBDIR%/distfiles/}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Home to vector gaming, Python style

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/pycadia \
		share/pixmaps/pycadia.png

PORTDATA=	*
PORTDOCS=	CHANGELOG INSTALL README TODO gravity.txt

do-install:
# Scripts
	@${PRINTF} "#!/bin/sh\n\ncd ${DATADIR} &&\
		./${PORTNAME}.py\n" > ${WRKDIR}/${PORTNAME}.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

# Data
.if !defined (NOPORTDATA)
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "glade pixmaps sounds *.*" ${DATADIR})
	@(cd ${DATADIR} && ${CHMOD} 755 pycadia.py spacewarpy.py vektoroids.py)
	${INSTALL_DATA} ${FILESDIR}/pycadia.conf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/logo1.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
.endif

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
