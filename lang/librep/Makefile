# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librep
PORTVERSION=	0.92.3
PORTREVISION=	1
CATEGORIES=	lang elisp gnome
MASTER_SITES=	http://download.tuxfamily.org/librep/%SUBDIR%/
MASTER_SITE_SUBDIR=	. Archive

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs Lisp like runtime library

LICENSE=	GPLv2

LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm \
		libffi.so:${PORTSDIR}/devel/libffi \
    		libgmp.so:${PORTSDIR}/math/gmp
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar

USE_CSTD=	gnu89

USES=		gettext gmake libtool pathfix pkgconfig readline tar:xz shebangfix
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

.include <bsd.port.pre.mk>

.if ${ARCH} == ia64
BROKEN=		Does not build on ia64
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/GDBM_LIBS/s|"-lgdbm"|"$$LIBS -lgdbm"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/share/man/|/man/|g' ${WRKSRC}/man/Makefile.in

pre-install:
	${FIND} ${WRKSRC} -name "*.so" -exec ${STRIP_CMD} {} \;

.include <bsd.port.post.mk>
