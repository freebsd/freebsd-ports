# New ports collection makefile for:    Jed text editor
# Date created:         22 APR 1997
# Whom:                 eric
#
# $FreeBSD$
#

PORTNAME=	jed
PORTVERSION=	0.99.19
CATEGORIES=	editors
MASTER_SITES=	ftp://space.mit.edu/pub/davis/jed/v${PORTVERSION:R}/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/v${PORTVERSION:R}/ \
		ftp://ftp.fu-berlin.de/pub/unix/editors/jed/v${PORTVERSION:R}/ \
		ftp://ftp.ntua.gr/pub/lang/slang/jed/v${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A SLang-based text editor

LIB_DEPENDS=   slang.2:${PORTSDIR}/devel/libslang2

CONFLICTS=	jed-devel-[0-9]*

OPTIONS=	X11 "Build xjed (depends of X11)" on

USE_BZIP2=	yes
DIST_SUBDIR=	jed
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ENV+=	JED_ROOT=${PREFIX}/lib/jed

PORTDOCS=	*
MAKE_ENV+=	DEST_DOC_DIR=${DOCSDIR}
.if defined(NOPORTDOCS)
MAKE_ENV+=	JED_DOC_FILES="" \
		JED_DOC_TXT_FILES="" \
		JED_DOC_HLP_FILES="" \
		JED_DOC_MAN_FILES=""
.endif

ALL_TARGET=	all getmail
MAN1=		jed.1 rgrep.1

.include <bsd.port.pre.mk>

LIB_DEPENDS+=	slang.2:${PORTSDIR}/devel/libslang2

.if defined(WITHOUT_X11)
PLIST_SUB+=	XJED="@comment "
.else
USE_XORG=	x11 ice xt
ALL_TARGET+=	xjed
PLIST_SUB+=	XJED=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,(DEST_JED_ROOT)/doc,(DEST_DOC_DIR),g' \
			  -e 's,\.\./info/\*,,' \
			  -e 's,^\(JED_DOC_.*FILES\) =,\1 \?=,g' \
		${WRKSRC}/src/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/MKINSDIR.*DEST_DOC_DIR/d' \
		${WRKSRC}/src/Makefile.in
.endif

post-configure:
	@${REINPLACE_CMD} -e 's,\(.usr.bin.install\) *-c,\1 -s -m 555,' \
		${WRKSRC}/src/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/vms_shell.com ${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/lib/README ${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/lib/jed.conf ${PREFIX}/lib/jed/lib

.include <bsd.port.post.mk>
