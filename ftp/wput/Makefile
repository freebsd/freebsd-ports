# Created by: Nosov Artem <chip-set@mail.ru>
# $FreeBSD$

PORTNAME=	wput
PORTVERSION=	0.6.2
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	chip-set@mail.ru
COMMENT=	Uploads files or directories to a ftpserver with support of resuming

PORTDOCS=	ABOUT-NLS COPYING ChangeLog INSTALL TODO
PORTEXAMPLES=	USAGE.examples USAGE.resumehandling USAGE.urlhandling \
		passwordfile wputrc

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${LDFLAGS}"
CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	TLS NLS DOCS EXAMPLES
OPTIONS_DEFAULT=	TLS

MAN1=		wdel.1 wput.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTLS}
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
CONFIGURE_ARGS+=	--enable-nls \
			--with-libintl-prefix=${LOCALBASE} \
			${ICONV_CONFIGURE_ARG}
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

.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/doc/,} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
