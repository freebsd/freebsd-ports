PORTNAME=	kraft
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	finance kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Manage invoices and documents for small companies
WWW=		https://volle-kraft-voraus.de/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		po4a:textproc/po4a \
		asciidoctor:textproc/rubygem-asciidoctor

# iconv is just used for run
USES=		cmake compiler:c++17-lang gettext-tools iconv \
		kde:6 qt:6 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	dragotin
USE_KDE=	config contacts i18n texttemplate \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicontacts
USE_QT=		base svg

SHEBANG_FILES=	manual/makeman.sh

post-patch:
	${REINPLACE_CMD} '/set(CMAKE_CXX_FLAGS.*-lstdc++fs")/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
