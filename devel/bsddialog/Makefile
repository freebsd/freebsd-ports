PORTNAME=	bsddialog
DISTVERSION=	1.0.1
CATEGORIES=	devel

MAINTAINER=	alfix86@gmail.com
COMMENT=	Text User Interface Widgets
WWW=		https://gitlab.com/alfix/bsddialog

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes
GL_ACCOUNT=	alfix

LIBDIR=		${WRKSRC}/lib
HEADERS=	${LIBDIR}/bsddialog.h ${LIBDIR}/bsddialog_progressview.h \
		${LIBDIR}/bsddialog_theme.h
UTILDIR=	${WRKSRC}/utility

MAKE_ARGS=	-DNORPATH

do-install:
	${INSTALL_DATA} ${HEADERS} ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${LIBDIR}/lib${PORTNAME}.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/
	${INSTALL} -l rs ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so
	${INSTALL_DATA} ${LIBDIR}/lib${PORTNAME}.a ${STAGEDIR}/${PREFIX}/lib
	${INSTALL_MAN} ${LIBDIR}/${PORTNAME}.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/
	${INSTALL_PROGRAM} ${UTILDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${UTILDIR}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
