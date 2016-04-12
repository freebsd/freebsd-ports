# Created by: Nosov Artem <chip-set@mail.ru>
# $FreeBSD$

PORTNAME=	wput
PORTVERSION=	0.6.2
PORTREVISION=	6
CATEGORIES=	ftp
MASTER_SITES=	SF

MAINTAINER=	chip-set@mail.ru
COMMENT=	Uploads files or directories to a ftpserver with support of resuming

PORTDOCS=	ABOUT-NLS COPYING ChangeLog INSTALL TODO
PORTEXAMPLES=	USAGE.examples USAGE.resumehandling USAGE.urlhandling \
		passwordfile wputrc

USES=		tar:tgz
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	TLS NLS DOCS EXAMPLES
OPTIONS_DEFAULT=TLS
OPTIONS_SUB=	yes

TLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
TLS_CONFIGURE_WITH=	ssl
NLS_USES=		gettext iconv
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_WITH=	libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}

pre-configure:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/src/memdbg.c \
		${WRKSRC}/src/socketlib.c

post-install:
	${INSTALL_MAN}	${WRKSRC}/doc/*.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
