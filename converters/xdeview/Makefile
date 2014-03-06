# Created by: Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
# $FreeBSD$

PORTNAME=	xdeview
PORTVERSION=	0.5.20
PORTREVISION=	3
CATEGORIES=	converters tcl tk
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/
DISTNAME=	uudeview-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 program for uu/xx/Base64/BinHex/yEnc de-/encoding

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	libuu.so:${PORTSDIR}/converters/uulib

USES+=		tk desthack
GNU_CONFIGURE=	yes
# Explicitly disable Tcl otherwise the configure script picks-up
# crud from the $PATH like /usr/opt/Simili/tcl/.
CONFIGURE_ARGS=	--disable-tcl --disable-tk
ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl

CPPFLAGS+=	-I${TCL_INCLUDEDIR} -DHAVE_TCL \
		-I${TK_INCLUDEDIR} -DHAVE_TK \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib \
		-lX11 -ltcl${TCL_VER:S/.//} \
		-ltk${TCL_VER:S/.//} -lm

PORTDOCS=	porting.notes
PLIST_FILES=	bin/uuwish bin/xdeview man/man1/xdeview.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/uuwish
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${FILESDIR}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
