# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cftp
PORTVERSION=	0.12
PORTREVISION=	4
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.giga.or.at/pub/nih/cftp/ \
		ftp://sunsite.univie.ac.at/pub/nih/cftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comfortable, full screen (S)FTP client

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sftp

PLIST_FILES=	bin/cftp
INFO=		cftp

.include <bsd.port.mk>
