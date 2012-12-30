# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gourmet
PORTVERSION=	0.15.9
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/grecipe-manager/0.15.8

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GNOME recipe manager

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}poppler>=0:${PORTSDIR}/graphics/py-poppler \
		${PYTHON_PKGNAMEPREFIX}rtf>=0:${PORTSDIR}/print/py-rtf \
		${PYTHON_PKGNAMEPREFIX}reportlab>=0:${PORTSDIR}/print/py-reportlab

MAN1=		${PORTNAME}.1
USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
USE_GETTEXT=	yes
USE_GNOME=	pygnome2 pygnomeextras pygtk2

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/tools/backup_gourmet_to_xml.py \
		${WRKSRC}/src/lib/gglobals.py \
		${WRKSRC}/src/lib/gtk_extras/chooserNotebook.py \
		${WRKSRC}/src/lib/gtk_extras/mnemonic_manager.py \
		${WRKSRC}/src/lib/plugins/import_export/pdf_plugin/print_plugin.py \
		${WRKSRC}/src/lib/plugins/nutritional_information/nutritionDisplay.py \
		${WRKSRC}/src/lib/plugins/nutritional_information/nutrition.py \
		${WRKSRC}/src/lib/backends/db.py \
		${WRKSRC}/src/gourmet
post-install:
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
