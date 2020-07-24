# Created by: mikeh@FreeBSD.org
# $FreeBSD$

PORTNAME=	check
PORTVERSION=	0.15.1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unit test framework for C

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		autoreconf libtool makeinfo pathfix pkgconfig

CONFIGURE_ENV=	ac_cv_path_AWK_PATH=${AWK}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

INFO=		check

GH_ACCOUNT=	libcheck
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} \
		-e 's|COPYING.LESSER||' \
		-e '/^docdir = / s|$$(PACKAGE)|check|' \
			${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} \
		-e '/^exampledir = / s|(docdir)/example|(datadir)/examples/check|' \
		-e '/^example[a-z]*dir = / s|(docdir)/example/|(exampledir)/|' \
			${WRKSRC}/doc/Makefile.am

.include <bsd.port.mk>
