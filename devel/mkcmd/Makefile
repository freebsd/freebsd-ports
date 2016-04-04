# Created by: ajk@waterspout.com
# $FreeBSD$

PORTNAME=	mkcmd
PORTVERSION=	8.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.physics.purdue.edu/pub/pundits/ \
		http://www.komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/


MAINTAINER=	cy@FreeBSD.org
COMMENT=	Command-line parser and manual page generator

BUILD_DEPENDS=	makeme:devel/msrc0

MAKE_FLAGS=
MAKEFILE=
USES=		desthack shebangfix tar:tgz
SHEBANG_LANG=	mkcmd
mkcmd_OLD_CMD=	mkcmd
mkcmd_CMD=	${PREFIX}/bin/mkcmd
SHEBANG_FILES=	${WRKSRC}/lib/mkcmd/*.m

post-patch:
.for f in bin/mkcmd/machine.h bin/mkcmd/mkcmd.man lib/mkcmd/mkcmd.man
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e "1s|/mkcmd|${mkcmd_CMD}|" ${WRKSRC}/lib/mkcmd/std_filter.m

do-build:
	@(cd ${WRKSRC}/bin/mkcmd && ${SETENV} ${MAKE_ENV} makeme \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
.for d in bin/mkcmd lib/mkcmd
	@(cd ${WRKSRC}/${d} && ${SETENV} ${MAKE_ENV} makeme \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
	${INSTALL_MAN} ${WRKSRC}/bin/mkcmd/mkcmd.man \
	    ${STAGEDIR}${PREFIX}/man/man1/mkcmd.1
	${INSTALL_MAN} ${WRKSRC}/lib/mkcmd/mkcmd.man \
	    ${STAGEDIR}${PREFIX}/man/man5/mkcmd.5

.include <bsd.port.mk>
