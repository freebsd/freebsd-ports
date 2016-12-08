# Created by: Damjan Marion <dmarion@open.hr>
# $FreeBSD$

PORTNAME=	gftp
PORTVERSION=	2.0.19
PORTREVISION=	6
CATEGORIES=	ftp
MASTER_SITES=	http://gftp.seul.org/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Free multithreaded GTK-based FTP and SFTP client

LICENSE=	GPLv2

USES=		pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20
USE_OPENSSL=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
