# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	recutils
PORTVERSION=	1.5
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	zeus@ibs.dn.ua
COMMENT=	Tools and libraries to access human-editable, plain text databases

LICENSE=	GPLv3

OPTIONS_DEFINE=	NLS DOCS

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		charsetfix

INFO=		${PORTNAME}
MAN1=		csv2rec.1 rec2csv.1 recdel.1 recfix.1 recfmt.1 recinf.1 \
		recins.1 recsel.1 recset.1
PORTDOCS=	ChangeLog NEWS README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
