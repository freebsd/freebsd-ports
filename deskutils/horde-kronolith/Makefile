# Created by: Thierry Thomas (<thierry@thomas.as>)
# $FreeBSD$

PORTNAME=	kronolith
PORTVERSION=	4.2.3
CATEGORIES=	deskutils www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde web based calendar

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFAULT=	DATE_HOLIDAYS TIMEOBJECTS
OPTIONS_DEFINE=		DATE_HOLIDAYS TIMEOBJECTS XMLWRITER
DATE_HOLIDAYS_DESC=	Depend on PEAR Date_Holidays
TIMEOBJECTS_DESC=	Depenbd on Horde timeobjects
XMLWRITER_DESC=		Depend on PHP xmlwriter extension

USES=	horde
USE_PHP=	gettext json simplexml
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

DATE_HOLIDAYS_RUN_DEPENDS=	${PEARDIR}/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays

TIMEOBJECTS_USE=	HORDE_RUN=timeobjects
XMLWRITER_USE=	PHP=xmlwriter

.include <bsd.port.mk>
