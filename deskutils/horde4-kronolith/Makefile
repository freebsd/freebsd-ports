# Ports collection makefile for:  Kronolith
# Date created:			  Sun Dec 02, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	kronolith
PORTVERSION=	3.0.6
CATEGORIES=	deskutils www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde web based calendar

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LATEST_LINK=	horde4-${PORTNAME}

OPTIONS=	DATE_HOLIDAYS "Install PEAR Date_Holidays" On \
		TIMEOBJECTS "Install Horde timeobjects" On \
		XMLWRITER "Depend on PHP xmlwriter extension" Off

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
		Horde_Url \
		Horde_Util \
		Horde_View

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DATE_HOLIDAYS)
RUN_DEPENDS+=	${PEARDIR}/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays
.endif

.if !defined(WITHOUT_TIMEOBJECTS)
USE_HORDE_RUN+=	timeobjects
.endif

.if defined(WITH_XMLWRITER)
USE_PHP+=	xmlwriter
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
