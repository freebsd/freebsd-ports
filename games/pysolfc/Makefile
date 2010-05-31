# New ports collection makefile for:	pysolfc
# Date created:		2009-03-13
# Whom:			Marcus von Appen
#
# $FreeBSD$
#

PORTNAME=	pysolfc
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/PySolFC/PySolFC-${PORTVERSION}
DISTNAME=	PySolFC-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Solitaire game, written in Python and the sucessor of PySol

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	PySolFC

DATADIR=	${PREFIX}/share/PySolFC
WRKSRC=		${WRKDIR}/${DISTNAME}
PORTDOCS=	README

OPTIONS=	NLS	"Native language support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${MV} ${WRKSRC}/pysol.py ${WRKSRC}/pysolfc
	@${REINPLACE_CMD} -e 's|pysol.py|pysolfc|' ${WRKSRC}/setup.py
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e "s|for l in ('ru', 'ru_RU')|for l in ()|" ${WRKSRC}/setup.py
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
