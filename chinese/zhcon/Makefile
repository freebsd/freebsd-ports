# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	zhcon
PORTVERSION=	0.2.6
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-0.2.5

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}-to-${PORTVERSION}.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast CJK (Chinese/Japanese/Korean) virtual console

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386
# Don't bother to add ".if !defined(WITHOUT_NLS)", zhcon requires libintl
USES=		gettext iconv
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message
MAN1=		zhcon.1
PORTDOCS=	*

OPTIONS_DEFINE=	BIG5 DOCS
BIG5_DESC=	Use Big5 by default (Taiwan, Hong Kong, Macau)

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&, ; s,doc/,${DOCSDIR},' \
		${WRKSRC}/doc/zhcon.1.in
	@${REINPLACE_CMD} -e 's,/dev/vga,/dev/ttyv0,' \
		${WRKSRC}/src/display/fbdev.cpp
	@${REINPLACE_CMD} -e 's,endian,sys/endian,' \
		${WRKSRC}/src/display/fblinear*.cpp
	@${REINPLACE_CMD} -e '/zhconpath/s,#,, ; s,/usr/lib,${PREFIX}/lib,' \
		${WRKSRC}/src/zhcon.conf
	@${REINPLACE_CMD} -e 's,$$enable_debug = ,x&x,' \
		${WRKSRC}/configure
.if ${PORT_OPTIONS:MBIG5}
	@${REINPLACE_CMD} -e '/defaultencode =/s,gb2312,big5,' \
		${WRKSRC}/src/zhcon.conf
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.html ${WRKSRC}/doc/bpsf.txt \
		${WRKSRC}/doc/poem.* ${WRKSRC}/ChangeLog ${WRKSRC}/NEWS \
		${WRKSRC}/README ${WRKSRC}/README.utf8 ${WRKSRC}/THANKS \
		${WRKSRC}/TODO ${DOCSDIR}
	${TAR} xf ${WRKSRC}/doc/html.tar.gz -C ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
