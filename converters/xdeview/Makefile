# New ports collection makefile for:	xdeview
# Date Created:		9 Feb 1997
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $FreeBSD$
#

PORTNAME=	xdeview
PORTVERSION=	0.5.20
PORTREVISION=	3
CATEGORIES=	converters tcl tk
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/
DISTNAME=	uudeview-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 program for uu/xx/Base64/BinHex/yEnc de-/encoding

LICENSE=	GPLv2

LIB_DEPENDS=	uu.3:${PORTSDIR}/converters/uulib

USE_TK_BUILD=	82+
USE_TK=		82+
GNU_CONFIGURE=	yes
# Explicitly disable Tcl otherwise the configure script picks-up
# crud from the $PATH like /usr/opt/Simili/tcl/.
CONFIGURE_ARGS=	--disable-tcl --disable-tk
ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${TCL_INCLUDEDIR} -DHAVE_TCL \
		-I${TK_INCLUDEDIR} -DHAVE_TK \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib \
		-lX11 -ltcl${TCL_VER:S/.//} \
		-ltk${TCL_VER:S/.//} -lm

MAN1=		xdeview.1
PORTDOCS=	porting.notes
PLIST_FILES=	bin/uuwish bin/xdeview

.include <bsd.port.pre.mk>

post-install:
	${STRIP_CMD} ${PREFIX}/bin/uuwish
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing documents to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${FILESDIR}/${file} ${DOCSDIR}
.endfor
.else
	@${ECHO_MSG} "===>  Not installing available documents"
.endif
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
