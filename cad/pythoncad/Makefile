# ex:ts=8
# Ports collection makefile for:	pythoncad
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pythoncad
PORTVERSION=	21
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.pythoncad.org/releases/
DISTNAME=	PythonCAD-DS1-R${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open-source CAD package built designed around Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.pth:${PORTSDIR}/x11-toolkits/py-gtk2

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes
USE_BZIP2=	yes

PLIST_FILES=	bin/gtkpycad

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gtkpycad.py ${PREFIX}/bin/gtkpycad
	@${FIND} ${PYTHON_SITELIBDIR}/PythonCAD* ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/PythonCAD* -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
