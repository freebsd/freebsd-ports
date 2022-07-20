PORTNAME=	m4
PORTVERSION=	1.4.19
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GNU M4

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe iconv tar:xz

CONFIGURE_ARGS=	--program-prefix=g
GNU_CONFIGURE=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/gm4

CPE_VENDOR=	gnu

OPTIONS_DEFINE=	EXAMPLES INFO LIBSIGSEGV NLS
OPTIONS_DEFAULT=INFO
OPTIONS_SUB=	yes
LIBSIGSEGV_DESC=Use alternative page fault handler (GNU libsigsegv)

INFO_CONFIGURE_ENV=	MAKEINFO="${MAKEINFO} --no-split"
INFO_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-no-info
INFO_INFO=		m4
INFO_USES=		makeinfo
LIBSIGSEGV_CONFIGURE_WITH=	libsigsegv-prefix=${LOCALBASE}
LIBSIGSEGV_LIB_DEPENDS=	libsigsegv.so:devel/libsigsegv
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e '/^* M4: / s|M4|G&|' ${WRKSRC}/doc/m4.texi
	@${REINPLACE_CMD} -e '/^install-exec-am: / s| .*||' ${WRKSRC}/lib/Makefile.in

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
