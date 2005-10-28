# New ports collection makefile for:    Jed text editor
# Date created:         22 APR 1997
# Whom:                 eric
#
# $FreeBSD$
#

PORTNAME=	jed
DISTVERSION=	0.99-17.135
CATEGORIES=	editors
MASTER_SITES=	ftp://space.mit.edu/pub/davis/jed/v0.99/pre-0.99-17/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-B${DISTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A SLang-based text editor. Development version

CONFLICTS=	jed-[0-9]*

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

OPTIONS=	X11 "Build xjed (depends of X11)" on \
		SLANG2 "Build using libslang-2.x" off

DIST_SUBDIR=	jed
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	JED_ROOT=${PREFIX}/lib/jed
MAKE_ENV+=	DEST_INFO_DIR=${PREFIX}/${INFO_PATH} \
		DEST_DOC_DIR=${DOCSDIR}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	*
.if defined(NOPORTDOCS)
MAKE_ENV+=	JED_DOC_FILES="" \
		JED_DOC_TXT_FILES="" \
		JED_DOC_MAN_FILES=""
.endif

ALL_TARGET=	all getmail
MAN1=		jed.1 rgrep.1
INFO=		jed

.include <bsd.port.pre.mk>

.if defined(WITH_SLANG2)
LIB_DEPENDS+=	slang.2:${PORTSDIR}/devel/libslang2
.else
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.endif

.if defined(WITHOUT_X11)
PLIST_SUB+=	XJED="@comment "
.else
USE_XLIB=	yes
ALL_TARGET+=	xjed
PLIST_SUB+=	XJED=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/src/jdmacros.h \
		${WRKSRC}/src/ledit.c
	@${REINPLACE_CMD} -e 's,__linux__,__FreeBSD__,g' \
		${WRKSRC}/src/pty.c
	@${REINPLACE_CMD} -e 's,(DEST_JED_ROOT)/doc,(DEST_DOC_DIR),g' \
			  -e 's,(DEST_JED_ROOT)/info,(DEST_INFO_DIR),g' \
			  -e 's,\.\./info/\*,../info/jed.info ../info/jed.info-\[0-9\],' \
			  -e 's,^\(JED_DOC_.*FILES\) =,\1 \?=,g' \
		${WRKSRC}/src/Makefile.in

pre-configure:
.for n in 1 2 3
	@${MV} ${WRKSRC}/info/jed.${n}in ${WRKSRC}/info/jed.info-${n}
.endfor
	@${REINPLACE_CMD} 's|jed.\([0-9]\)in|jed.info-\1|' \
		${WRKSRC}/info/jed.info

post-configure:
	@${REINPLACE_CMD} -e 's,\(.usr.bin.install\) *-c,\1 -s -m 555,' \
		${WRKSRC}/src/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/vms_shell.com ${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/lib/README ${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/lib/jed.conf ${PREFIX}/lib/jed/lib

.include <bsd.port.post.mk>
