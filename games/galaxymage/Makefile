# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	galaxymage
PORTVERSION=	0.3.0
PORTREVISION=	10
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/tactics/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source tactical and strategic RPG

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.txt

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/_numpy.so:${PORTSDIR}/math/py-numeric \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

USES=		gettext python:run twisted
NO_BUILD=	yes

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-configure:
	@${REINPLACE_CMD} -e 's@%%DATADIR%%@${DATADIR}@g' ${WRKSRC}/GalaxyMage.py ${WRKSRC}/src/Resources.py
	@${REINPLACE_CMD} -e 's@%%LOCALBASE%%@${LOCALBASE}@g' ${WRKSRC}/src/Translate.py

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/GalaxyMage.py ${STAGEDIR}${PREFIX}/bin/GalaxyMage
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for DIRE in src data
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(py|pyc|txt|TXT|ogg|wav|png|ttf|conf)" -exec ${INSTALL_DATA} "{}" \
			"${STAGEDIR}${DATADIR}/{}" \;
.endfor

.for FILE in de en fr nl sp
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${FILE}/LC_MESSAGES && \
		${INSTALL_DATA} ${WRKSRC}/locale/${FILE}/LC_MESSAGES/* \
			${STAGEDIR}${PREFIX}/share/locale/${FILE}/LC_MESSAGES
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(html|css|txt|png)" -exec ${INSTALL_DATA} "{}" \
			"${STAGEDIR}${DOCSDIR}/{}" \;
	@${INSTALL_DATA} ${WRKSRC}/CREDITS.txt ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
