# New ports collection makefile for:	wput
# Date created:				2 December 2003
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	wput
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	chip-set@mail.ru
COMMENT=	Uploads files or directories to a ftpserver with support of resuming

LIB_DEPENDS=	gnutls.26:${PORTSDIR}/security/gnutls

PORTDOCS=	ABOUT-NLS COPYING ChangeLog INSTALL TODO
PORTEXAMPLES=	USAGE.examples USAGE.resumehandling USAGE.urlhandling \
		passwordfile wputrc

USE_GETTEXT=	yes
USE_AUTOTOOLS=	autoconf:261
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LIBS="${LDFLAGS}"

OPTIONS=	TLS "Enable TLS support" on \
		MEM_DEBUG "Enable memory debugging" off \
		DEBUG "Enable debug support" on

MAN1=		wput.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_TLS)
CONFIGURE_ARGS+=	--without-ssl
.endif
.if defined(WITH_MEM_DEBUG)
CONFIGURE_ARGS+=	--enable-memdbg
.endif
.if defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	--disable-g-switch
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/socketlib.c

post-install:
	@${INSTALL_MAN}	${WRKSRC}/doc/${MAN1} ${MANPREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/doc/,} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
