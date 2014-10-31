# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	glchess
PORTVERSION=	1.0.6
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D OpenGL based chess game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext

USES=		desktop-file-utils python shared-mime-info
USE_GNOME=	gconf2
USE_PYTHON=	distutils
GCONF_SCHEMAS=	glchess.schemas

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

post-patch:
	@${GREP} -lR "/usr/share/games/glchess" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/share/games/glchess|${DATADIR}|g'
	@${REINPLACE_CMD} -e 's|share/games/glchess|share/glchess|g ; \
		 s|share/gconf/schemas|etc/gconf/schemas|g' ${WRKSRC}/setup.py

post-build:
.if ${PORT_OPTIONS:MNLS}
	@(for lang in `${MAKE} -f ${WRKSRC}/Makefile -V LANGUAGES` ; do \
		cd ${WRKSRC}/po ; \
		${LOCALBASE}/bin/msgfmt $$lang.po -o $$lang.mo ; \
	done)
.endif

post-install:
.if ${PORT_OPTIONS:MNLS}
	@(for lang in `${MAKE} -f ${WRKSRC}/Makefile -V LANGUAGES` ; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/$$lang/LC_MESSAGES ; \
		${INSTALL_DATA} ${WRKSRC}/po/$$lang.mo \
		${STAGEDIR}${PREFIX}/share/locale/$$lang/LC_MESSAGES/glchess.mo ; \
	done)
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
