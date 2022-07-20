PORTNAME=	lrzsz
PORTVERSION=	0.12.20
PORTREVISION=	4
CATEGORIES=	comms
MASTER_SITES=	http://ohse.de/uwe/releases/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Receive/Send files via X/Y/ZMODEM protocol (unrestrictive)

LICENSE=	GPLv2

USES=		cpe

CPE_VENDOR=	lrzsz_project

GNU_CONFIGURE=	yes
ALL_TARGET=	all # vcheck

CONFLICTS_INSTALL=	lrzip # bin/lrz

OPTIONS_DEFINE=	NLS

NLS_USES=		gettext
NLS_PLIST_FILES=	share/locale/de/LC_MESSAGES/lrzsz.mo
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
