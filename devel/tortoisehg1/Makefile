# New ports collection makefile for:	tortoisehg-hgtk
# Date created:		11 January 2011
# Whom:			arrowdodger <6yearold@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tortoisehg
PORTVERSION=	1.1.9.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/tortoisehg/targz/downloads/

MAINTAINER=	6yearold@gmail.com
COMMENT=	hgtk script from TortoiseHG

RUN_DEPENDS=	hg:${PORTSDIR}/devel/mercurial \
		${PYTHON_SITELIBDIR}/iniparse/ini.py:${PORTSDIR}/devel/py-iniparse

OPTIONS=	NAUTILUS "Install TortoiseHG Nautilus extension" off

USE_GNOME=	pygtk2 pygobject
INSTALLS_ICONS=	yes

USE_PYTHON=	yes
INSTALLS_EGGINFO=yes

.include <bsd.port.options.mk>

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.endif

.if defined(WITHOUT_NAUTILUS)
PLIST_SUB+=	NAUTILUS="@comment "
.else
PLIST_SUB+=	NAUTILUS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e '/_path/ s|/usr|${PREFIX}|' ${WRKSRC}/${PYSETUP}
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e '150,152 s|^|# |' ${WRKSRC}/${PYSETUP}
.endif
.if defined(WITHOUT_NAUTILUS)
	@${REINPLACE_CMD} -e '153,154 s|^|# |' ${WRKSRC}/${PYSETUP}
.endif

do-configure:
	@${DO_NADA}

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} build

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} install --prefix=${PREFIX}
	${MKDIR} ${PREFIX}/share/tortoisehg
	${INSTALL_DATA} ${WRKSRC}/contrib/mergetools.rc ${PREFIX}/share/tortoisehg/

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
