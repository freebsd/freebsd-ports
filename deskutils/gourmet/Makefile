# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gourmet
PORTVERSION=	0.16.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	https://launchpadlibrarian.net/133161899/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GNOME recipe manager

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distutils-extra>0:${PORTSDIR}/devel/py-distutils-extra
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}poppler>=0:${PORTSDIR}/graphics/py-poppler \
		${PYTHON_PKGNAMEPREFIX}rtf>=0:${PORTSDIR}/print/py-rtf \
		${PYTHON_PKGNAMEPREFIX}reportlab>=0:${PORTSDIR}/print/py-reportlab \
		${PYTHON_PKGNAMEPREFIX}elib.intl>0:${PORTSDIR}/textproc/py-elib.intl

MAN1=		gourmet.1
PORTDOCS=	FAQ LICENSE
PORTSCOUT=	ignore:1

USE_BZIP2=	yes
USES=		gettext
USE_GNOME=	pygnome2 pygnomeextras pygtk2
USE_PYTHON=	2
USE_PYDISTUTILS=yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/gourmet/backends/db.py \
		${WRKSRC}/gourmet/gtk_extras/chooserNotebook.py \
		${WRKSRC}/gourmet/gtk_extras/mnemonic_manager.py \
		${WRKSRC}/gourmet/plugins/import_export/pdf_plugin/print_plugin.py \
		${WRKSRC}/gourmet/plugins/nutritional_information/nutritionDisplay.py \
		${WRKSRC}/gourmet/plugins/nutritional_information/nutrition.py \
		${WRKSRC}/gourmet/plugins/web_plugin/gourmetweb/manage.py \
		${WRKSRC}/tools/backup_gourmet_to_xml.py

post-install:
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
