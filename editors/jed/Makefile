# Created by: eric
# $FreeBSD$

PORTNAME=	jed
PORTVERSION=	0.99.19
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	ftp://space.mit.edu/pub/davis/jed/v${PORTVERSION:R}/ \
		ftp://ftp.fu-berlin.de/pub/unix/editors/jed/v${PORTVERSION:R}/ \
		ftp://ftp.ntua.gr/pub/lang/slang/jed/v${PORTVERSION:R}/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A SLang-based text editor

LICENSE=	GPLv2

LIB_DEPENDS=	libslang.so:${PORTSDIR}/devel/libslang2

CONFLICTS=	jed-devel-[0-9]*

OPTIONS_DEFINE=	X11 PERMS HOSTLOOKUP DOCS
OPTIONS_DEFAULT=X11 HOSTLOOKUP DOCS
OPTIONS_SUB=	X11

PERMS_DESC=	Respect permissions by Root
HOSTLOOKUP_DESC=Look-up for hostname

USE_BZIP2=	yes
DIST_SUBDIR=	jed
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ENV+=	JED_ROOT=${PREFIX}/lib/jed

PORTDOCS=	*
MAKE_ENV+=	DEST_DOC_DIR=${STAGEDIR}${DOCSDIR}
.if empty(PORT_OPTIONS:MDOCS)
MAKE_ENV+=	JED_DOC_FILES="" \
		JED_DOC_TXT_FILES="" \
		JED_DOC_HLP_FILES="" \
		JED_DOC_MAN_FILES=""
.endif

ALL_TARGET=	all getmail

X11_USE=	XORG=x11 XORG=ice XORG=xt
X11_ALL_TARGET=	xjed

.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MHOSTLOOKUP)
HOSTNAME_CMD=	/bin/hostname
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src__userinfo.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,(DEST_JED_ROOT)/doc,(DEST_DOC_DIR),g' \
			  -e 's,\.\./info/\*,,' \
			  -e 's,^\(JED_DOC_.*FILES\) =,\1 \?=,g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/MKINSDIR.*DEST_DOC_DIR/d' \
		${WRKSRC}/src/Makefile.in
.if empty(PORT_OPTIONS:MPERMS)
	@${REINPLACE_CMD} 's|jed_file_is_readonly (file, 1)|jed_file_is_readonly (file, 0)|' ${WRKSRC}/src/file.c
.endif
.if empty(PORT_OPTIONS:MHOSTLOOKUP)
	@${REINPLACE_CMD} -e "s/%%JED_HOSTNAME%%/$$(${HOSTNAME_CMD})/" \
		${WRKSRC}/src/userinfo.c
.endif

post-configure:
	@${REINPLACE_CMD} -e 's,\(.usr.bin.install\) *-c,\1 -s -m 555,' \
		${WRKSRC}/src/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/vms_shell.com ${STAGEDIR}${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/lib/README ${STAGEDIR}${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/lib/jed.conf ${STAGEDIR}${PREFIX}/lib/jed/lib

.include <bsd.port.post.mk>
