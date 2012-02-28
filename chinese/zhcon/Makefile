# New ports collection makefile for:	Zhcon
# Date created:				Sun Sep 9, 2001
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

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
USE_ICONV=	yes
# Don't bother to add ".if !defined(WITHOUT_NLS)", zhcon requires libintl
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message
MAN1=		zhcon.1
PORTDOCS=	*

OPTIONS=	BIG5	"Use Big5 by default (Taiwan, Hong Kong, Macau)" off

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
.if defined(WITH_BIG5)
	@${REINPLACE_CMD} -e '/defaultencode =/s,gb2312,big5,' \
		${WRKSRC}/src/zhcon.conf
.endif

post-install:
.if !defined(NOPORTDOCS)
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
