PORTNAME=	librep
PORTVERSION=	0.92.7
PORTREVISION=	7
CATEGORIES=	lang elisp gnome
MASTER_SITES=	http://download.tuxfamily.org/librep/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Emacs Lisp like runtime library
WWW=		https://sawfish.tuxfamily.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libgdbm.so:databases/gdbm \
		libffi.so:devel/libffi \
		libgmp.so:math/gmp
RUN_DEPENDS=	gtar:archivers/gtar

USES=		autoreconf gettext gmake libtool localbase:ldflags \
		pathfix pkgconfig readline shebangfix tar:xz
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

SHEBANG_FILES=	${WRKSRC}/src/rep-xgettext.jl
SHEBANG_LANG=	rep
rep_OLD_CMD=	/usr/bin/rep
rep_CMD?=	${PREFIX}/bin/rep

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-aclocaldir=${PREFIX}/share/aclocal \
		--with-stack-direction=-1

LDFLAGS+=	-pthread

OPTION_DEFINE=	INFO
OPTION_DEFAULT=	INFO

INFO_USES=		makeinfo
INFO_INFO=		librep

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -E 's|(INSTALL_PROGRAM\))( [^-])|\1 -m 755\2|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/SUBDIRS/s|man||' ${WRKSRC}/Makefile.in

post-build-INFO-on:
	cd ${WRKSRC}/man && \
		makeinfo --no-split  -I . librep.texi -o librep.info

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-INFO-on:
	${INSTALL_DATA} ${WRKSRC}/docs/librep.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
