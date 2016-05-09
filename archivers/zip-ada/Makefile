# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zip-ada
PORTVERSION=	50
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	SF/unzip-ada/
DISTNAME=	zipada${PORTVERSION}_f1

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Zip compressed archive file format library written in Ada

LICENSE=	MIT

USES=		ada perl5 dos2unix zip
USE_PERL5=	build
WRKSRC=		${WRKDIR}/zip-ada
MAKE_ENV+=	Build_Mode=Optimize
ZTOOLS=		bunzip comp_zip find_zip lz lzma_dec random_data rezip zipada
DEMOS=		demo_csv_into_zip demo_unzip demo_zip test_chunk \
		test_extract test_extract_tb test_lz_scramble \
		test_stream_performance test_unz_streams \
		test_zip_info_timing za_gnat zip_with_many_files ziptest

PORTSCOUT=	ignore:50_f1	# Portscout currently showing false positive

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -P zipada.gpr)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		  ${STAGEDIR}${EXAMPLESDIR} \
		  ${STAGEDIR}${PREFIX}/include/zip-ada \
		  ${STAGEDIR}${PREFIX}/lib/zip-ada \
		  ${STAGEDIR}${PREFIX}/lib/gnat
	@${MKDIR} ${WRKSRC}/obj_tools ${WRKSRC}/obj_demos
.for F in ${ZTOOLS}
	${INSTALL_PROGRAM} ${WRKSRC}/${F} ${STAGEDIR}${PREFIX}/bin/
	${MV} ${WRKSRC}/obj_opt/${F}.* ${WRKSRC}/obj_tools/
.endfor
.for F in ${DEMOS}
	${INSTALL_PROGRAM} ${WRKSRC}/${F} ${STAGEDIR}${EXAMPLESDIR}/
	${MV} ${WRKSRC}/obj_opt/${F}.* ${WRKSRC}/obj_demos/
.endfor
	(cd ${WRKSRC}/obj_opt && ${AR} rcs libzip-ada.a *.o)
	${MV} ${STAGEDIR}${PREFIX}/bin/bunzip \
		${STAGEDIR}${PREFIX}/bin/debzip2
	${INSTALL_DATA} ${WRKSRC}/zip_lib/*.ad[sb] \
		${STAGEDIR}${PREFIX}/include/zip-ada/
	${INSTALL_DATA} ${WRKSRC}/obj_opt/*.ali \
		${STAGEDIR}${PREFIX}/lib/zip-ada/
	${INSTALL_DATA} ${WRKSRC}/obj_opt/*.a ${STAGEDIR}${PREFIX}/lib/zip-ada/
	${INSTALL_DATA} ${FILESDIR}/zip-ada.gpr ${STAGEDIR}${PREFIX}/lib/gnat/

.include <bsd.port.mk>
