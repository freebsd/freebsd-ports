# Created by:				Dave Grochowski
# $FreeBSD$

PORTNAME=	gccmakedep
PORTVERSION=	1.0.2
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Create dependencies in makefiles using 'gcc -M'

XORG_CAT=	util

MAN1=		gccmakedep.1

PLIST_FILES=	bin/gccmakedep

.include <bsd.port.pre.mk>

# Attempt to force use of GNU cpp, if it is installed as /usr/bin/gcpp.
.if (${OSVERSION} >= 900506 && ${OSVERSION} < 1000000) || \
    ${OSVERSION} >= 1000010
CONFIGURE_ENV+=	ac_cv_path_RAWCPP="gcpp"
.endif

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' ${WRKSRC}/configure

.include <bsd.port.post.mk>
