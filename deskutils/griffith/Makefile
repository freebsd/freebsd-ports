# New ports collection makefile for:	griffith
# Date created:		27 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

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

OPTIONS=	LXML "Enable lxml support" off \
		REPORTLAB2 "Enable ReportLab2 support" off \
		CHARDET "Enable chardet support" off \
		PYGNOMEEXTRAS "Enable python-gnome-extras support" off

USE_XZ=		yes
USE_GNOME=	pygtk2
USE_PYTHON=	2.5+
USE_GETTEXT=	yes
USE_GMAKE=	yes
NO_BUILD=	yes

MANLANG=	"" pl pt
MAN1=		${PORTNAME}.1

.include <bsd.port.options.mk>

.if defined(WITH_LXML)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml
.endif

.if defined(WITH_REPORTLAB2)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab2>=2:${PORTSDIR}/print/py-reportlab2
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab>=1.19:${PORTSDIR}/print/py-reportlab
.endif

.if defined(WITH_CHARDET)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}chardet>=0:${PORTSDIR}/textproc/py-chardet
.endif

.if defined(WITH_PYGNOMEEXTRAS)
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
