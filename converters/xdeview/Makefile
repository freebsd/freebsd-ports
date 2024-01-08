PORTNAME=	xdeview
PORTVERSION=	0.5.20
PORTREVISION=	4
CATEGORIES=	converters tcl tk
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/
DISTNAME=	uudeview-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 program for uu/xx/Base64/BinHex/yEnc de-/encoding
WWW=		http://www.fpx.de/fp/Software/UUDeview/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libuu.so:converters/uulib

USES=		desthack localbase:ldflags tk

GNU_CONFIGURE=	yes
# Explicitly disable Tcl otherwise the configure script picks-up
# crud from the $PATH like /usr/opt/Simili/tcl/.
CONFIGURE_ARGS=	--disable-tcl --disable-tk
ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl

CPPFLAGS+=	-I${TCL_INCLUDEDIR} -DHAVE_TCL \
		-I${TK_INCLUDEDIR} -DHAVE_TK
LDFLAGS+=	-lX11 -ltcl${TCL_VER:S/.//} \
		-ltk${TCL_VER:S/.//} -lm

PLIST_FILES=	bin/uuwish bin/xdeview share/man/man1/xdeview.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/uuwish
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/porting.notes ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
