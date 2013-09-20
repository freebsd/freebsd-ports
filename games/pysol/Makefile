# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pysol
PORTVERSION=	4.82
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.pysol.org/download/pysol/:source \
		${MASTER_SITE_LOCAL:S/$/:support/}
MASTER_SITE_SUBDIR=	tg/:support
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:support \
		${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX}:source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Solitaire game, written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pysolsoundserver.so:${PORTSDIR}/audio/pysol-sound-server \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter

USE_BZIP2=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

MAN6=		pysol.6

NO_STAGE=	yes
post-patch:
	@${RM} ${WRKSRC}/src/tk/soundoptionsdialog.py.orig
	@${REINPLACE_CMD} -e "s|@pkgdatadir@|${DATADIR}|" \
		-e "s|@prefix@|${PREFIX}|" \
		-e "s|@PYTHON@|${PYTHON_CMD}|" ${WRKSRC}/pysol
	@${REINPLACE_CMD} -e "s|pysol_\$$PYVER.pyc|src/pysol.py|" \
		${WRKSRC}/pysol

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pysol ${PREFIX}/bin/pysol
	${INSTALL_DATA} ${WRKSRC}/pysol.6 ${PREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/data; tar -cf - .) | \
		(cd ${DATADIR}; tar --unlink -xf -)
	(cd ${WRKSRC}; tar -cf - src) | \
		(cd ${DATADIR}; tar --unlink -xf -)
	@cd ${DATADIR} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py src

.include <bsd.port.mk>
