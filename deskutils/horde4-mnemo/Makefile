# Ports collection makefile for:  Mnemo
# Date created:			  Sun May 19, 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mnemo
PORTVERSION=	3.0.3
CATEGORIES=	deskutils www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde web based notes manager

LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/LICENSE

LATEST_LINK=	horde4-${PORTNAME}

OPTIONS=	PDF "Support PDF generation" On

USE_PHP=	gettext
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
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

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PDF)
USE_HORDE_RUN+=	Horde_Pdf
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
