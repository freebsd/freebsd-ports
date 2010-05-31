# New ports collection makefile for:	wput
# Date created:				2 December 2003
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	wput
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	chip-set@mail.ru
COMMENT=	Uploads files or directories to a ftpserver with support of resuming

PORTDOCS=	ABOUT-NLS COPYING ChangeLog INSTALL TODO
PORTEXAMPLES=	USAGE.examples USAGE.resumehandling USAGE.urlhandling \
		passwordfile wputrc

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS}" \
		LIBS="${LDFLAGS}"
MAKE_JOBS_UNSAFE=yes

OPTIONS=	TLS "Enable TLS support" On \
		NLS "Native Language Support with gettext" On

MAN1=		wdel.1 wput.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TLS)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if !defined(WITHOUT_NLS)
USE_ICONV=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls \
			--with-libintl-prefix=${LOCALBASE} \
			--with-libiconv-prefix=${LOCALBASE}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls --without-libiconv-prefix
PLIST_SUB=	NLS="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/src/memdbg.c \
		${WRKSRC}/src/socketlib.c

post-install:
	@${INSTALL_MAN}	${MAN1:S,^,${WRKSRC}/doc/,} ${MANPREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/doc/,} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
