# New ports collection makefile for:	tortoisehg-hgtk
# Date created:		11 January 2011
# Whom:			arrowdodger <6yearold@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tortoisehg
PORTVERSION=	1.1.10
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/tortoisehg/targz/downloads/

MAINTAINER=	6yearold@gmail.com
COMMENT=	hgtk script from TortoiseHG

RUN_DEPENDS=	hg:${PORTSDIR}/devel/mercurial \
		${PYTHON_SITELIBDIR}/iniparse/ini.py:${PORTSDIR}/devel/py-iniparse

DEPRECATED=	does not work with current devel/mercurial, use tortoisehg2
EXPIRATION_DATE=2011-11-22

OPTIONS=	NAUTILUS "Install TortoiseHG Nautilus extension" off

CONFLICTS=	tortoisehg-2*
LATEST_LINK=	${PORTNAME}1

USE_GNOME=	pygtk2 pygobject
INSTALLS_ICONS=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
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
	@${REINPLACE_CMD} -e 's/^%%NLS%%/# /' ${WRKSRC}/${PYSETUP}
.else
	@${REINPLACE_CMD} -e 's/^%%NLS%%//' ${WRKSRC}/${PYSETUP}
.endif
.if defined(WITHOUT_NAUTILUS)
	@${REINPLACE_CMD} -e 's/^%%NAUTILUS%%/# /' ${WRKSRC}/${PYSETUP}
.else
	@${REINPLACE_CMD} -e 's/^%%NAUTILUS%%//' ${WRKSRC}/${PYSETUP}
.endif

post-install:
	${MKDIR} ${PREFIX}/share/tortoisehg
	${INSTALL_DATA} ${WRKSRC}/contrib/mergetools.rc ${PREFIX}/share/tortoisehg/

	@${ECHO_MSG}
	@${CAT} pkg-message
	@${ECHO_MSG}

.include <bsd.port.mk>
