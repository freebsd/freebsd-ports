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

MAN1=		hsftp.1
PLIST_FILES=	bin/hsftp

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSH}
RUN_DEPENDS+=	ssh:${PORTSDIR}/security/openssh-portable
CONFIGURE_ARGS+=	--with-openssh
.endif

.if ${PORT_OPTIONS:MREADLINE}
USES+=			readline
CONFIGURE_ARGS+=	--with-readline
.endif

pre-patch:
	${REINPLACE_CMD} -e '2343d' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hsftp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hsftp.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
