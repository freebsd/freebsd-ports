PORTNAME=	kraft
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
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

# iconv is just used for run
USES=		cmake compiler:c++11-lang gettext-tools grantlee:5 iconv \
		kde:5 qt:5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	dragotin
USE_KDE=	config contacts i18n \
		ecm:build
USE_QT=		core gui sql svg widgets xml xmlpatterns \
		buildtools:build qmake:build testlib:build

SHEBANG_FILES=	manual/makeman.sh

.include <bsd.port.mk>
