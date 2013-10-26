# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	glchess
PORTVERSION=	1.0.6
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A 3D OpenGL based chess game

RUN_DEPENDS=	${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext

USE_GNOME=	gconf2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

GCONF_SCHEMAS=	glchess.schemas

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
PLIST_SUB+=	NLS="@comment"
CONFIGURE_ARGS+=	--disable-nls
.endif

post-patch:
	@${GREP} -lR "/usr/share/games/glchess" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/share/games/glchess|${DATADIR}|g'
	@${REINPLACE_CMD} -e 's|share/games/glchess|share/glchess|g ; \
		 s|share/gconf/schemas|etc/gconf/schemas|g' ${WRKSRC}/setup.py

post-build:
	@(for lang in `${MAKE} -f ${WRKSRC}/Makefile -V LANGUAGES` ; do \
		cd ${WRKSRC}/po ; \
		${LOCALBASE}/bin/msgfmt $$lang.po -o $$lang.mo ; \
	done)

post-install:
	@(for lang in `${MAKE} -f ${WRKSRC}/Makefile -V LANGUAGES` ; do \
		${MKDIR} ${PREFIX}/share/locale/$$lang/LC_MESSAGES ; \
		${INSTALL_DATA} ${WRKSRC}/po/$$lang.mo \
		${PREFIX}/share/locale/$$lang/LC_MESSAGES/glchess.mo ; \
	done)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif #NOPORTDOCS
	@-update-mime-database ${PREFIX}/share/mime
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
