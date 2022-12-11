PORTNAME=	kronolith
PORTVERSION=	4.2.29
CATEGORIES=	deskutils www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde web based calendar
WWW=		https://www.horde.org/apps/kronolith/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

IGNORE_WITH_PHP=80 81 82

RUN_DEPENDS+=	${PEARDIR}/Date.php:devel/pear-Date@${PHP_FLAVOR}

USES=		horde php cpe
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		content \
		horde \
		Horde_Auth \
		Horde_Autoloader \
		Horde_Core \
		Horde_Data \
		Horde_Date \
		Horde_Date_Parser \
		Horde_Dav \
		Horde_Exception \
		Horde_Form \
		Horde_Group \
		Horde_Http \
		Horde_History \
		Horde_Icalendar \
		Horde_Image \
		Horde_Lock \
		Horde_LoginTasks \
		Horde_Mail \
		Horde_Mime \
		Horde_Nls \
		Horde_Notification \
		Horde_Perms \
		Horde_Serialize \
		Horde_Share \
		Horde_Support \
		Horde_Text_Filter \
		Horde_Timezone \
		Horde_Url \
		Horde_Util \
		Horde_View
USE_PHP=	gettext json simplexml

OPTIONS_DEFINE=		DATE_HOLIDAYS TIMEOBJECTS XMLWRITER
OPTIONS_DEFAULT=	DATE_HOLIDAYS TIMEOBJECTS
DATE_HOLIDAYS_DESC=	Depend on PEAR Date_Holidays
TIMEOBJECTS_DESC=	Depenbd on Horde timeobjects
XMLWRITER_DESC=		Depend on PHP xmlwriter extension

DATE_HOLIDAYS_RUN_DEPENDS=	${PEARDIR}/Date/Holidays.php:devel/pear-Date_Holidays@${PHP_FLAVOR}
TIMEOBJECTS_USE=	HORDE_RUN=timeobjects
XMLWRITER_USE=	PHP=xmlwriter

.include <bsd.port.mk>
