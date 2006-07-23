# New ports collection makefile for:	xgngeo
# Date created:		2006-03-02
# Whom:			Jose Alonso Cardenas Marquez <acardebas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	xgngeo
PORTVERSION=	15
CATEGORIES=	emulators games
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	gngeo

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Fronted (GUI) for gngeo

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.pth:${PORTSDIR}/x11-toolkits/py-gtk2 \
		gngeo:${PORTSDIR}/emulators/gngeo

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/${PORTNAME}.py \
		${WRKSRC}/data/py/configfile.py
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/${PORTNAME}.py \
		${WRKSRC}/data/py/configfile.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xgngeo.py ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/rominfos.dtd ${WRKSRC}/data/rominfos.xml ${DATADIR}

.for DIRE in img py
	${MKDIR} ${DATADIR}/${DIRE}
	@cd ${WRKSRC}/data/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/${DIRE}/{}" \; && \
			${FIND} -E * -type f -iregex ".*\.(py|pyc|png|po|mo)" \
				-exec ${INSTALL_DATA} "{}" "${DATADIR}/${DIRE}/{}" \;
.endfor

.for LANG in es fr pl pt_BR
	@cd ${WRKSRC}/data/lang/${LANG}/LC_MESSAGES && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/share/locale/${LANG}/LC_MESSAGES/{}" \;
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/xgngeo-doc.pdf ${WRKSRC}/doc/xgngeo-doc.txt  ${DOCSDIR}
.endif

.include <bsd.port.mk>
