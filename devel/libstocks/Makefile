# New ports collection makefile for:    libstocks
# Date created:         this 7th day of January, 2002
# Whom:                 Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	libstocks
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com

#GNU_CONFIGURE=	yes

post-patch:
	${PERL} -pi -e 's/malloc.h/stdlib.h/; s/__UNIX__/__unix__/' \
		${WRKSRC}/lib/*.c

do-build do-install:
.for d in lib client
	cd ${WRKSRC}/$d && ${ENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} -j2 \
		-f ${FILESDIR}/Makefile.$d ${.TARGET:S/do-//}
.endfor

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
