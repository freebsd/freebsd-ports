# $FreeBSD$
#    $MCom: ports/devel/gcvs/Makefile,v 1.1 2006/10/07 17:10:25 ahze Exp $

PORTNAME=	gcvs
PORTVERSION=	1.0
PORTREVISION=	13
PORTEPOCH=	1
CATEGORIES=	devel tk
MASTER_SITES=	SF/cvsgui/gCvs/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-end interface client for CVS

LICENSE=	GPLv2

BROKEN=		Does not build

USE_GNOME=	gtk12
USE_TCL_BUILD=	yes
USE_TCL_WRAPPER=yes
USE_TK_WRAPPER=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --force --copy --gnu
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS:N-std=*:N:}"
CONFIGURE_ARGS=	--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tcllib=${TCL_LIBDIR}
MAKE_JOBS_SAFE=	yes

MAN1=		cvs.1
MAN5=		cvs.5
MAN8=		cvsbug.8
INFO=		cvs cvsclient

pre-configure:
	@(cd ${WRKSRC}/cvsunix && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})

.include <bsd.port.mk>
