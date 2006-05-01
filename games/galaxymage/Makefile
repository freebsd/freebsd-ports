# New ports collection makefile for:	galaxymage
# Date created:		2006-01-30
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	galaxymage
PORTVERSION=	0.2.1
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/tactics/

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Open source tactical and strategic RPG

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/_numpy.so:${PORTSDIR}/math/py-numeric \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_DOS2UNIX=	yes
NO_BUILD=	yes

OPTIONS=	PSYCO	"Use just-in-time Python compiler" off

.include <bsd.port.pre.mk>

.if defined(WITH_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

post-configure:
	@${REINPLACE_CMD} -e 's@%%DATADIR%%@${DATADIR}@g' ${WRKSRC}/GalaxyMage.py ${WRKSRC}/src/Resources.py
	@${REINPLACE_CMD} -e 's@%%DOCSDIR%%@${DOCSDIR}@g' ${WRKSRC}/src/Main.py
	@${REINPLACE_CMD} -e 's@%%X11BASE%%@${X11BASE}@g' ${WRKSRC}/src/Translate.py

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/GalaxyMage.py ${PREFIX}/bin/GalaxyMage
	@${MKDIR} ${DATADIR} ${DOCSDIR}
.for DIRE in src data
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(py|pyc|txt|TXT|ogg|wav|png|ttf)" -exec ${INSTALL_DATA} "{}" \
			"${DATADIR}/{}" \;
.endfor

.for FILE in en fr sp
	@${MKDIR} ${PREFIX}/share/locale/${FILE}/LC_MESSAGES && \
		${INSTALL_DATA} ${WRKSRC}/locale/${FILE}/LC_MESSAGES/GalaxyMage.mo \
			${WRKSRC}/locale/${FILE}/LC_MESSAGES/GalaxyMage.pot ${PREFIX}/share/locale/${FILE}/LC_MESSAGES
.endfor

	@cd ${WRKSRC}/doc && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(html|css|txt|png)" -exec ${INSTALL_DATA} "{}" \
			"${DOCSDIR}/{}" \;

.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/CREDITS.txt ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
