# New ports collection makefile for:   librep
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/lang/librep/Makefile,v 1.2 2006/09/10 00:51:12 mezz Exp $

PORTNAME=	librep
PORTVERSION=	0.92.1b
CATEGORIES=	lang elisp gnome
MASTER_SITES=	http://download.tuxfamily.org/librep/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Emacs Lisp like runtime library

LICENSE=	GPLv2

LIB_DEPENDS=	gdbm.4:${PORTSDIR}/databases/gdbm \
		ffi.5:${PORTSDIR}/devel/libffi \
    		gmp.10:${PORTSDIR}/math/gmp
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar

USE_CSTD=	gnu89

USE_XZ=		yes
USE_GNOME=	gnomehack
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-aclocaldir=${PREFIX}/share/aclocal \
		--with-stack-direction=-1
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MANCOMPRESSED=	yes
MAN1=		rep.1 rep-remote.1 rep-xgettext.1 repdoc.1
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
