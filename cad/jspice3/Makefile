# New ports collection makefile for:	Jspice
# Date created:         26 Feb 2006
# Whom:                 Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	jspice3
PORTVERSION=	2.5
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/	\
		ftp://ftp.srware.com/pub/

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	An adaptation of the Berkeley Spice3f4 with superconductivity

CONFLICTS=	spice-[0-9]*

OPTIONS=	X "Use X window system" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X)
USE_XLIB=	yes
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's+/usr/local+${PREFIX}+g ;	\
	 s+-O -g+${CFLAGS}+g;' \
		${WRKSRC}/conf/unixconf/mkheader.0
.if !defined(WITHOUT_X)
	@${REINPLACE_CMD} -e 's+#%%WITH_X%%++g' 		\
		${WRKSRC}/conf/unixconf/mkheader.0
.else
	@${ECHO} "#undef HAVE_X11" >> ${WRKSRC}/src/include/spice.h
.endif

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

.include <bsd.port.post.mk>
