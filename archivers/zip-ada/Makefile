# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zip-ada
PORTVERSION=	52
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SF/unzip-ada/
DISTNAME=	zipada${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zip compressed archive file format library written in Ada

LICENSE=	MIT

USES=		ada perl5 dos2unix zip
USE_PERL5=	build
WRKSRC=		${WRKDIR}/zip-ada
MAKE_ENV+=	Build_Mode=Fast
ZTOOLS=		zipada \
		comp_zip \
		find_zip \
		rezip \
		za_gnat \
		rz_gnat \
		bunzip \
		lz \
		lzma_dec \
		lzma_enc \
		lz77_stats \
		random_data \
		several_sizes
DEMOS=		demo_csv_into_zip \
		demo_zip \
		demo_unzip \
		test_unz_streams \
		test_chunk \
		ziptest \
		zip_with_many_files \
		test_zip_info_timing \
		test_stream_performance \
		test_extract \
		test_extract_tb \
		test_lz_scramble \
		test_llhc \
		test_lz77

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -p -P zipada.gpr)

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
