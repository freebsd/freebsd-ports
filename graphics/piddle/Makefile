# Ports collection makefile for:	piddle
# Date created:				29 Feb 2000
# Whom:					dom@myrddin.demon.co.uk
#
# $FreeBSD$
#

PORTNAME=	piddle
PORTVERSION=	1.0b1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}-5.tgz

MAINTAINER=	dom@myrddin.demon.co.uk

USE_PYTHON=	yes
NO_BUILD=	yes

PIDDLEDIR=	${PYTHON_SITELIBDIR}/piddle
PIDDLEDOCDIR=	${PREFIX}/share/doc/piddle
PIDDLEEGDIR=	${PREFIX}/share/examples/piddle

post-extract:
	@${ECHO} "===>  Removing DOS line endings."
.for file in pdfdoc.py pdfgen.py pdfgeom.py pdfmetrics.py pdfutils.py piddlePDF.py
	@${TR} -d '\r' < ${WRKSRC}/${file} > ${WRKSRC}/${file}.new
	@${MV} ${WRKSRC}/${file}.new ${WRKSRC}/${file}
.endfor

do-install:
	${MKDIR} ${PIDDLEDIR}/pilfonts
	${INSTALL_DATA} ${WRKSRC}/*.py ${PIDDLEDIR}
	${INSTALL_DATA} ${WRKSRC}/pilfonts/*.pil ${PIDDLEDIR}/pilfonts
	${INSTALL_DATA} ${WRKSRC}/pilfonts/*.pbm ${PIDDLEDIR}/pilfonts
	${INSTALL_DATA} ${WRKSRC}/pilfonts/metrics.dat ${PIDDLEDIR}/pilfonts
	${ECHO} 'piddle' > ${PIDDLEDIR}.pth
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PIDDLEDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PIDDLEDIR}
	${MKDIR} ${PIDDLEDOCDIR}
	(cd ${WRKSRC}/docs ; tar cf - *) | \
		(cd ${PIDDLEDOCDIR} ; tar xf -)
	${MKDIR} ${PIDDLEEGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PIDDLEEGDIR}

.include <bsd.port.mk>
