PORTNAME=	wxformbuilder
DISTVERSION=	4.2.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/wxFormBuilder/wxFormBuilder/releases/download/v${DISTVERSION}/
DISTNAME=	wxFormBuilder-${DISTVERSION}-source-full

MAINTAINER=	FreeBSD@Shaneware.Biz
COMMENT=	WYSIWYG GUI Designer and Code Generator for wxWidgets
WWW=		https://github.com/wxFormBuilder/wxFormBuilder/

LICENSE=	GPLv2

LIB_DEPENDS=	libtinyxml2.so:textproc/tinyxml2

USES=		cmake compiler:c++17-lang desktop-file-utils shared-mime-info
USE_LDCONFIG=	yes
USE_WX=		3.2+

EXTRACT_AFTER_ARGS=	--exclude third_party/tinyxml2 \
			--no-same-owner --no-same-permissions

WRKSRC=		${WRKDIR}/${DISTNAME:S|-source-full||}

.include <bsd.port.mk>
