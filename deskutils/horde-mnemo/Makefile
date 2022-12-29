PORTNAME=	mnemo
PORTVERSION=	4.2.14
PORTREVISION=	1
CATEGORIES=	deskutils www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde web based notes manager
WWW=		https://www.horde.org/apps/mnemo/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Requires php74
EXPIRATION_DATE=	2023-03-31
BROKEN=	runtime error with php80

USES=		horde php cpe
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		content \
		Horde_Auth \
		Horde_Core \
		Horde_Data \
		Horde_Exception \
		Horde_Form \
		Horde_Group \
		Horde_History \
		Horde_Icalendar \
		Horde_Injector \
		Horde_Perms \
		Horde_Prefs \
		Horde_Share \
		Horde_Support \
		Horde_Text_Filter \
		Horde_Util
USE_PHP=	gettext
IGNORE_WITH_PHP=81 82

OPTIONS_DEFINE=		PDF
OPTIONS_DEFAULT=	PDF
PDF_DESC=		Support PDF generation

PDF_USE=	HORDE_RUN=Horde_Pdf

.include <bsd.port.mk>
