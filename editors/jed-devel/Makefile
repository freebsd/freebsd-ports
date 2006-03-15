# New ports collection makefile for:    Jed text editor
# Date created:         22 APR 1997
# Whom:                 eric
#
# $FreeBSD$
#

PORTNAME=	jed
DISTVERSION=	0.99-17.165
CATEGORIES=	editors
MASTER_SITES=	http://download.gna.org/jed/v0.99/devel/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-B${DISTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A SLang-based text editor. Development version

CONFLICTS=	jed-[0-9]*

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

OPTIONS=	X11 "Build xjed (depends of X11)" on \
		SLANG2 "Build using libslang-2.x" off

USE_BZIP2=	yes
DIST_SUBDIR=	jed
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	JED_ROOT=${PREFIX}/lib/jed
MAKE_ENV+=	DEST_DOC_DIR=${DOCSDIR}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	*
.if defined(NOPORTDOCS)
MAKE_ENV+=	JED_DOC_FILES="" \
		JED_DOC_TXT_FILES="" \
		JED_DOC_MAN_FILES=""
.endif

ALL_TARGET=	all getmail
MAN1=		jed.1 rgrep.1

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
	@${REINPLACE_CMD} -e 's,(DEST_JED_ROOT)/doc,(DEST_DOC_DIR),g' \
			  -e 's,\.\./info/\*,,' \
			  -e 's,^\(JED_DOC_.*FILES\) =,\1 \?=,g' \
		${WRKSRC}/src/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's,\(.usr.bin.install\) *-c,\1 -s -m 555,' \
		${WRKSRC}/src/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/vms_shell.com ${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/lib/README ${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/lib/jed.conf ${PREFIX}/lib/jed/lib

.include <bsd.port.post.mk>
