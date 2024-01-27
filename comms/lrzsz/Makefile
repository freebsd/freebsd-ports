PORTNAME=	lrzsz
PORTVERSION=	0.12.20
PORTREVISION=	6
CATEGORIES=	comms
MASTER_SITES=	http://ohse.de/uwe/releases/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Receive/Send files via X/Y/ZMODEM protocol (unrestrictive)
WWW=		https://ohse.de/uwe/software/lrzsz.html

LICENSE=	GPLv2

USES=		cpe

CPE_VENDOR=	lrzsz_project

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
ALL_TARGET=	all # vcheck

CONFLICTS_INSTALL=	lrzip # bin/lrz

OPTIONS_DEFINE=	NLS

NLS_USES=		gettext
NLS_PLIST_FILES=	share/locale/de/LC_MESSAGES/lrzsz.mo
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	${REINPLACE_CMD} '/checking for syslog/,+140d' ${WRKSRC}/configure

.include <bsd.port.mk>
