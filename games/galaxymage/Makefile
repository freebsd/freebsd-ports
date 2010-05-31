# New ports collection makefile for:	galaxymage
# Date created:		2006-01-30
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	galaxymage
PORTVERSION=	0.3.0
PORTREVISION=	6
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/tactics/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Open source tactical and strategic RPG

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/_numpy.so:${PORTSDIR}/math/py-numeric \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

USE_PYTHON=	yes
USE_TWISTED=	yes
USE_GETTEXT=	yes
NO_BUILD=	yes

OPTIONS=	PSYCO	"Use just-in-time Python compiler" off

.include <bsd.port.pre.mk>

.if defined(WITH_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

post-configure:
	@${REINPLACE_CMD} -e 's@%%DATADIR%%@${DATADIR}@g' ${WRKSRC}/GalaxyMage.py ${WRKSRC}/src/Resources.py
	@${REINPLACE_CMD} -e 's@%%LOCALBASE%%@${LOCALBASE}@g' ${WRKSRC}/src/Translate.py

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/GalaxyMage.py ${PREFIX}/bin/GalaxyMage
	@${MKDIR} ${DATADIR}
.for DIRE in src data
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(py|pyc|txt|TXT|ogg|wav|png|ttf|conf)" -exec ${INSTALL_DATA} "{}" \
			"${DATADIR}/{}" \;
.endfor

.for FILE in de en fr nl sp
	@${MKDIR} ${PREFIX}/share/locale/${FILE}/LC_MESSAGES && \
		${INSTALL_DATA} ${WRKSRC}/locale/${FILE}/LC_MESSAGES/* \
			${PREFIX}/share/locale/${FILE}/LC_MESSAGES
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(html|css|txt|png)" -exec ${INSTALL_DATA} "{}" \
			"${DOCSDIR}/{}" \;
	@${INSTALL_DATA} ${WRKSRC}/CREDITS.txt ${WRKSRC}/README.txt ${DOCSDIR}
.endif
.include <bsd.port.post.mk>
