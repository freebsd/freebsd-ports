# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zip-ada
PORTVERSION=	45
CATEGORIES=	archivers
MASTER_SITES=	SF/unzip-ada/
DISTNAME=	zipada${PORTVERSION}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Zip compressed archive file format library written in Ada

LICENSE=	MIT

USES=		ada perl5
USE_PERL5=	build
USE_DOS2UNIX=	yes
EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}/zip-ada
MAKE_ENV+=	Build_Mode=Optimize
ZTOOLS=		zipada comp_zip find_zip rezip bunzip lz
DEMOS=		demo_zip demo_unzip ziptest demo_csv_into_zip test_extract \
		test_extract_tb test_unz_streams za_gnat test_chunk \
		zip_with_many_files

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -P zipada.gpr

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		  ${STAGEDIR}${EXAMPLESDIR} \
		  ${STAGEDIR}${PREFIX}/include/zip-ada \
		  ${STAGEDIR}${PREFIX}/lib/zip-ada \
		  ${STAGEDIR}${PREFIX}/lib/gnat
	@${MKDIR} ${WRKSRC}/obj_tools ${WRKSRC}/obj_demos
.for F in ${ZTOOLS}
	@${INSTALL_PROGRAM} ${WRKSRC}/${F} ${STAGEDIR}${PREFIX}/bin/
	@${MV} ${WRKSRC}/obj_opt/${F}.* ${WRKSRC}/obj_tools/
.endfor
.for F in ${DEMOS}
	@${INSTALL_PROGRAM} ${WRKSRC}/${F} ${STAGEDIR}${EXAMPLESDIR}/
	@${MV} ${WRKSRC}/obj_opt/${F}.* ${WRKSRC}/obj_demos/
.endfor
	@cd ${WRKSRC}/obj_opt && ${AR} rcs libzip-ada.a *.o
	@${MV} ${STAGEDIR}${PREFIX}/bin/bunzip ${STAGEDIR}${PREFIX}/bin/debzip2
	@${INSTALL_DATA} ${WRKSRC}/zip_lib/*.ad[sb] \
		${STAGEDIR}${PREFIX}/include/zip-ada/
	@${INSTALL_DATA} ${WRKSRC}/obj_opt/*.ali \
		${STAGEDIR}${PREFIX}/lib/zip-ada/
	@${INSTALL_LIB} ${WRKSRC}/obj_opt/*.a ${STAGEDIR}${PREFIX}/lib/zip-ada/
	@${INSTALL_DATA} ${FILESDIR}/zip-ada.gpr ${STAGEDIR}${PREFIX}/lib/gnat/

.include <bsd.port.mk>
