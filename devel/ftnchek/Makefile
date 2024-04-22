PORTNAME=	ftnchek
PORTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SUNSITE/devel/lang/fortran \
		http://www.dsm.fordham.edu/~ftnchek/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortran 77 semantic checking utility
WWW=		https://www.dsm.fordham.edu/~ftnchek/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	skipv:3.3.a,3.3.b,3.3.c

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
CONFIGURE_ENV=	ac_cv_path_CC="${CC}" ac_cv_path_EMACS="${TRUE}"
MAKE_ARGS=	OPT="${CFLAGS}"

.include <bsd.port.mk>
