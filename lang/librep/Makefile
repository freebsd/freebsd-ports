# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librep
PORTVERSION=	0.92.5
CATEGORIES=	lang elisp gnome
MASTER_SITES=	http://download.tuxfamily.org/librep/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Emacs Lisp like runtime library

LICENSE=	GPLv2

LIB_DEPENDS=	libgdbm.so:databases/gdbm \
		libffi.so:devel/libffi \
		libgmp.so:math/gmp
RUN_DEPENDS=	gtar:archivers/gtar

USE_CSTD=	gnu89

USES=		gettext gmake libtool makeinfo pathfix pkgconfig readline \
		shebangfix tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-aclocaldir=${PREFIX}/share/aclocal \
		--with-stack-direction=-1
SHEBANG_FILES=	${WRKSRC}/src/rep-xgettext.jl
SHEBANG_LANG=	rep
rep_OLD_CMD=	/usr/bin/rep
rep_CMD?=	${PREFIX}/bin/rep
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

INFO=		librep

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -E 's|(INSTALL_PROGRAM\))( [^-])|\1 -m 755\2|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
