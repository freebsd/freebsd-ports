# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	generic_image_decoder
PORTVERSION=	06
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://sourceforge.net/projects/${SFPATH}/
DISTNAME=	gid-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ada library for decoding various image formats inc. animations

LICENSE=	MIT

USES=		ada zip dos2unix
SFPATH=		gen-img-dec/files
WRKSRC=		${WRKDIR}/gid
MAKE_ENV+=	Build_Mode=Fast_but_checked
PORTDOCS=	gid.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${FILESDIR}/construct.gpr ${WRKSRC}
	${MKDIR} ${WRKSRC}/src ${WRKDIR}/data
	${MV} ${WRKSRC}/gid_work.xls ${WRKDIR}/data
	(cd ${WRKSRC}; ${MV} *.ad[bs] src)

post-patch:
	@${REINPLACE_CMD} -e "s|-j2|-j${MAKE_JOBS_NUMBER}|" \
		${WRKSRC}/gid.gpr

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -p -Pconstruct)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -Pgid)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/generic_image_decoder \
		${STAGEDIR}${PREFIX}/include/generic_image_decoder
	${INSTALL_DATA} ${FILESDIR}/generic_image_decoder.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/src/* \
		${STAGEDIR}${PREFIX}/include/generic_image_decoder
	${INSTALL_DATA} ${WRKSRC}/lib/*  \
		${STAGEDIR}${PREFIX}/lib/generic_image_decoder
	(cd ${WRKSRC}/test && ${INSTALL_PROGRAM} to_bmp mini \
		${STAGEDIR}${PREFIX}/bin)

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/gid.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
