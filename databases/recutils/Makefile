# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	recutils
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	zeus@ibs.dn.ua
COMMENT=	Tools and libraries to access human-editable, plain text databases

LICENSE=	GPLv3

USES=		charsetfix libtool makeinfo
GNU_CONFIGURE=	yes
.ifdef QEMU_EMULATING
# XXX bug 224740: configure hangs
CONFIGURE_ENV=	gl_cv_func_printf_enomem=no
.endif
USE_LDCONFIG=	yes

INFO=		rec-mode recutils
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
