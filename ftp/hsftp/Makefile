# Created by: will
# $FreeBSD$

PORTNAME=	hsftp
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://la-samhna.de/hsftp/ \
		http://www.alaskaparadise.com/freebsd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTP emulator that uses ssh to transport commands/data

LICENSE=	GPLv2

OPTIONS_DEFINE=	OPENSSH READLINE
OPTIONS_DEFAULT=READLINE
OPENSSH_DESC=	Build with OpenSSH support
READLINE_DESC=	Enable readline support

GNU_CONFIGURE=	yes
MAKEFILE=	makefile

PLIST_FILES=	bin/hsftp man/man1/hsftp.1.gz

OPENSSH_RUN_DEPENDS=		ssh:security/openssh-portable
OPENSSH_CONFIGURE_WITH=		openssh

READLINE_USES=			readline
READLINE_CONFIGURE_WITH=	readline

pre-patch:
	${REINPLACE_CMD} -e '2343d' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hsftp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hsftp.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
