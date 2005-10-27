# New ports collection makefile for:    Jed text editor
# Date created:         22 APR 1997
# Whom:                 eric
#
# $FreeBSD$
#

PORTNAME=	jed
PORTVERSION=	0.99.16
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://space.mit.edu/pub/davis/jed/v${PORTVERSION:R}/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/v${PORTVERSION:R}/ \
		ftp://ftp.fu-berlin.de/pub/unix/editors/jed/v${PORTVERSION:R}/ \
		ftp://ftp.ntua.gr/pub/lang/slang/jed/v${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A SLang-based text editor

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

CONFLICTS=	jed-devel-[0-9]*

USE_REINPLACE=	yes

OPTIONS=	X11 "Build xjed (depends of X11)" on

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	JED_ROOT=${PREFIX}/lib/jed \
		CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV+=	DEST_INFO_DIR=${PREFIX}/${INFO_PATH} \
		DEST_DOC_DIR=${DOCSDIR} \
		STRIP_CMD=${STRIP_CMD}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(NOPORTDOCS)
MAKE_ENV+=	JED_WITHOUT_DOCS=yes
.endif

ALL_TARGET=	all getmail ${XJED}
MAN1=		jed.1 rgrep.1
INFO=		jed

.include <bsd.port.pre.mk>

.if defined(WITHOUT_X11)
PLIST_SUB+=	NOXJED="@comment "
.else
USE_XLIB=	yes
XJED=		xjed
PLIST_SUB+=	NOXJED=""
MAKE_ENV+=	XJED=yes
.endif

DIST_SUBDIR=	jed
pre-configure:
.for n in 1 2 3
	@${MV} ${WRKSRC}/info/jed.${n}in ${WRKSRC}/info/jed.info-${n}
.endfor
	@${REINPLACE_CMD} 's|jed.\([0-9]\)in|jed.info-\1|' \
		${WRKSRC}/info/jed.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/vms_shell.com ${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/lib/README ${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/lib/jed.conf ${PREFIX}/lib/jed/lib

.include <bsd.port.post.mk>
