# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	griffith
PORTVERSION=	0.13
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/87859599/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight film collection manager

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy06>=0.5:${PORTSDIR}/databases/py-sqlalchemy06 \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${PYXML}

OPTIONS_DEFINE=	LXML REPORTLAB2 CHARDET PYGNOMEEXTRAS
LXML_DESC=	Enable lxml support
REPORTLAB2_DESC=	Enable ReportLab2 support
CHARDET_DESC=	Enable chardet support
PYGNOMEEXTRAS_DESC=	Enable python-gnome-extras support

USE_XZ=		yes
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USES=		gettext
USE_GMAKE=	yes
NO_BUILD=	yes

MANLANG=	"" pl pt
MAN1=		${PORTNAME}.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLXML}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml
.endif

.if ${PORT_OPTIONS:MREPORTLAB2}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab2>=2:${PORTSDIR}/print/py-reportlab2
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab>=1.19:${PORTSDIR}/print/py-reportlab
.endif

.if ${PORT_OPTIONS:MCHARDET}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}chardet>=0:${PORTSDIR}/textproc/py-chardet
.endif

.if ${PORT_OPTIONS:MPYGNOMEEXTRAS}
USE_GNOME+=	pygnomeextras
.endif

post-patch:
.for file in Makefile
	@${REINPLACE_CMD} -e \
		'/^LANGUAGES=/s|find.*|cd i18n/\&\&ls -d *)|g ; \
		 /^PREFIX/s|^|#|g ; \
		 /^ETCDIR/s|=.*|= $$(PREFIX)/etc|g' ${WRKSRC}/${file}
.endfor
.for file in docs/en/Makefile docs/pl/Makefile docs/pt/Makefile
	@${REINPLACE_CMD} -e \
		'/^PREFIX/s|^|#|g ; \
		 /^MANDIR/s|=.*|=${MANPREFIX}/man|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
