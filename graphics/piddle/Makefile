# Ports collection makefile for:	piddle
# Version required:			1.0b1
# Date created:				29 Feb 2000
# Whom:					dom@myrddin.demon.co.uk
#
# $FreeBSD$
#

DISTNAME=	piddle-1.0b1-5
PKGNAME=	piddle-1.0b1
CATEGORIES=	graphics python
MASTER_SITES=	http://download.sourceforge.net/piddle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dom@myrddin.demon.co.uk

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

WRKSRC=		${WRKDIR}/${PKGNAME}
NO_BUILD=	yes

PYTHON?=	${LOCALBASE}/bin/python
PYTHONLIBDIR?=	${LOCALBASE}/lib/python1.5
PIDDLEDIR=	${PYTHONLIBDIR}/site-packages/piddle
PIDDLEDOCDIR=	${PREFIX}/share/doc/piddle
PIDDLEEGDIR=	${PREFIX}/share/examples/piddle

post-extract:
	@${ECHO} "===>  Removing DOS line endings."
.for file in pdfdoc.py pdfgen.py pdfgeom.py pdfmetrics.py pdfutils.py piddlePDF.py
	@${TR} -d '\r' < ${WRKSRC}/${file} > ${WRKSRC}/${file}.new
	@${MV} ${WRKSRC}/${file}.new ${WRKSRC}/${file}
.endfor

do-install:
	${MKDIR} ${PIDDLEDIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${PIDDLEDIR}
	${ECHO} 'piddle' > ${PIDDLEDIR}.pth
	@${PYTHON} ${PYTHONLIBDIR}/compileall.py ${PIDDLEDIR}
	@${PYTHON} -O ${PYTHONLIBDIR}/compileall.py ${PIDDLEDIR}
	${MKDIR} ${PIDDLEDOCDIR}
	(cd ${WRKSRC}/docs ; tar cf - *) | \
		(cd ${PIDDLEDOCDIR} ; tar xf -)
	${MKDIR} ${PIDDLEEGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PIDDLEEGDIR}

.include <bsd.port.mk>
