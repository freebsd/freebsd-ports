# New ports collection makefile for:	glchess
# Date created:				Wed Jul 18 08:35:56 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	glchess
PORTVERSION=	0.9.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D OpenGL based chess game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GETTEXT=	yes

post-patch:
	@${GREP} -lR "/usr/share/games/glchess" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/share/games/glchess|${DATADIR}|g'
	@${REINPLACE_CMD} -e 's|share/games|share|g' ${WRKSRC}/setup.py

post-build:
.for lang in de en en_AU en_NZ en_US
	cd ${WRKSRC}/po && ${LOCALBASE}/bin/msgfmt ${lang}.po -o ${lang}.mo
.endfor

post-install:
.for lang in de en en_AU en_NZ en_US
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/glchess.mo
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif #NOPORTDOCS
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
