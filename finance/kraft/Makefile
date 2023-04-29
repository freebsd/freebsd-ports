PORTNAME=	kraft
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	finance kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Manage invoices and documents for small companies
WWW=		https://volle-kraft-voraus.de/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		po4a:textproc/po4a \
		rubygem-asciidoctor>=1.5.7<3:textproc/rubygem-asciidoctor
LIB_DEPENDS=	libctemplate.so:textproc/google-ctemplate

USES=		cmake compiler:c++11-lang grantlee:5 kde:5 qt:5 shebangfix
USE_KDE=	akonadi akonadicontacts \
		auth codecs config configwidgets contacts coreaddons \
		grantleetheme i18n itemmodels widgetsaddons
USE_QT=		core dbus gui sql widgets xml \
		buildtools:build qmake:build
CFLAGS+=	-I${LOCALBASE}/include/KPim5

SHEBANG_FILES=	manual/makeman.sh

USE_GITHUB=	yes
GH_ACCOUNT=	dragotin

.include <bsd.port.mk>
