# New ports collection makefile for:    PySol
# Date created:         11 September 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pysol
PORTVERSION=	4.60
CATEGORIES=	games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/pysol/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} pysol.py.bz2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	bunzip2:${PORTSDIR}/archivers/bzip2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes

MAN6=		pysol.6

post-extract:
	${LOCALBASE}/bin/bunzip2 -c ${DISTDIR}/pysol.py.bz2 \
		> ${WRKSRC}/pysol.py

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${WRKSRC}

do-install:
	${SED}	-e "s|@pkgdatadir@|${PREFIX}/share/pysol|" \
		-e "s|^exec python|exec ${PYTHON_CMD}|" \
		< ${WRKSRC}/pysol > ${PREFIX}/bin/pysol
	${CHMOD} +x ${PREFIX}/bin/pysol
	${INSTALL_DATA} ${WRKSRC}/pysol.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)
	${INSTALL_DATA} ${WRKSRC}/pysol.pyc ${PREFIX}/share/pysol

.include <bsd.port.mk>
