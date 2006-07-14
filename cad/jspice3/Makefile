# New ports collection makefile for:	Jspice
# Date created:         26 Feb 2006
# Whom:                 Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	jspice3
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/	\
		ftp://ftp.srware.com/pub/

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	An adaptation of the Berkeley Spice3f4 with superconductivity

CONFLICTS=	spice-[0-9]*

USE_XLIB=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's+/usr/local+${PREFIX}+g ;	\
	 s+-O -g+${CFLAGS}+g;' \
		${WRKSRC}/conf/unixconf/mkheader.0

do-build:
	@(cd ${WRKSRC};${SETENV} ${MAKE_ENV} ${SH} build)

do-install:
	@(cd ${WRKSRC}/src/bin;${SETENV} ${MAKE_ENV} ${MAKE} install)

post-install:
.if !defined(NOPORTDOCS)
	${MV} ${PREFIX}/lib/jspice3/examples ${EXAMPLESDIR}
.else
	${RM} -R ${PREFIX}/lib/jspice3/examples
.endif

.include <bsd.port.mk>
