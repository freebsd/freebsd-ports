PORTNAME=	jed
DISTVERSION=	0.99-19
PORTREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.fu-berlin.de/pub/unix/editors/jed/v${PORTVERSION:R}/ \
		ftp://ftp.ntua.gr/pub/lang/slang/jed/v${PORTVERSION:R}/
DIST_SUBDIR=	jed

MAINTAINER=	garga@FreeBSD.org
COMMENT=	SLang-based text editor
WWW=		https://www.jedsoft.org/jed/

LICENSE=	GPLv2

LIB_DEPENDS=	libslang.so:devel/libslang2

USES=		tar:bzip2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV+=	JED_ROOT=${PREFIX}/lib/jed

MAKE_ENV+=	DEST_DOC_DIR=${STAGEDIR}${DOCSDIR}
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	all getmail

CONFLICTS=	ja-jed

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS HOSTLOOKUP PERMS X11
OPTIONS_DEFAULT=	HOSTLOOKUP X11
OPTIONS_SUB=	yes

HOSTLOOKUP_DESC=	Look-up for hostname
PERMS_DESC=	Respect permissions by Root

X11_USES=	xorg
X11_USE=	XORG=ice \
		XORG=x11 \
		XORG=xt
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
