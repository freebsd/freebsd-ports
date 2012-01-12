# New ports collection makefile for:    py-stl
# Date created:                         28 Dec 2011
# Whom:                                 rsmith@xs4all.nl
#
# $FreeBSD$

PORTNAME=		stl
PORTVERSION=		3.0
CATEGORIES=		graphics python
MASTER_SITES=		http://rsmith.home.xs4all.nl/software/
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		py-${PORTNAME}-${GITVER}

MAINTAINER=		rsmith@xs4all.nl
COMMENT=		Converts STL models to POV-Ray meshes or PostScript/PDF images

RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}reportlab2>2:${PORTSDIR}/print/py-reportlab2

GITVER=			31a5b12

USE_ZIP=		YES
USE_PYTHON=		2.5+
USE_PYDISTUTILS=	YES

CONFLICTS=		stl2pov-[0-9]*

MAN1=			stl2ps.1 stlinfo.1 stl2pdf.1

NO_BUILD=		YES

post-install:
	@${INSTALL_MAN} ${WRKSRC}/stl2ps.1 ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/stlinfo.1 ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/stl2pdf.1 ${MANPREFIX}/man/man1
	@${MV} ${PREFIX}/bin/stl2ps.py  ${PREFIX}/bin/stl2ps
	@${MV} ${PREFIX}/bin/stl2pov.py ${PREFIX}/bin/stl2pov
	@${MV} ${PREFIX}/bin/stlinfo.py ${PREFIX}/bin/stlinfo
	@${MV} ${PREFIX}/bin/stl2pdf.py ${PREFIX}/bin/stl2pdf
	@${MV} ${PYTHON_SITELIBDIR}/py_stl-${GITVER}-py${PYTHON_VER}.egg-info ${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}

.include <bsd.port.mk>
