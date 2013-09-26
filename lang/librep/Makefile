# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librep
PORTVERSION=	0.92.3
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

USE_XZ=		yes
USES=		gettext pathfix pkgconfig readline gmake
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-aclocaldir=${PREFIX}/share/aclocal \
		--with-stack-direction=-1
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

.include <bsd.port.post.mk>
