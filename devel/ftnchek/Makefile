# Created by: kargl@apl.washington.edu
# $FreeBSD$

PORTNAME=	ftnchek
PORTVERSION=	3.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.dsm.fordham.edu/~ftnchek/download/
MASTER_SITE_SUBDIR=	devel/lang/fortran

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Fortran 77 semantic checking utility

LICENSE=	MIT

PORTSCOUT=	skipv:3.3.a,3.3.b,3.3.c

MAN1=		dcl2inc.1 ftnchek.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
CONFIGURE_ENV=	ac_cv_path_CC="${CC}" ac_cv_path_EMACS="${TRUE}"
MAKE_ARGS=	OPT="${CFLAGS}"

.include <bsd.port.mk>
