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
USE_ZIP=	yes
USE_DOS2UNIX=	yes
WRKSRC=		${WRKDIR}/zip-ada
DESTINY=	${WRKDIR}/destino
MAKE_ENV+=	Build_Mode=Optimize
ZTOOLS=		zipada comp_zip find_zip rezip bunzip lz
DEMOS=		demo_zip demo_unzip ziptest demo_csv_into_zip test_extract \
		test_extract_tb test_unz_streams za_gnat test_chunk \
		zip_with_many_files

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -P zipada.gpr
	@${MKDIR} ${DESTINY}${PREFIX}/bin \
		  ${DESTINY}${EXAMPLESDIR} \
		  ${DESTINY}${PREFIX}/include/zip-ada \
		  ${DESTINY}${PREFIX}/lib/zip-ada \
		  ${DESTINY}${PREFIX}/lib/gnat
	@${MKDIR} ${WRKSRC}/obj_tools ${WRKSRC}/obj_demos
.for F in ${ZTOOLS}
	@${INSTALL_PROGRAM} ${WRKSRC}/${F} ${DESTINY}${PREFIX}/bin/
	@${MV} ${WRKSRC}/obj_opt/${F}.* ${WRKSRC}/obj_tools/
.endfor
.for F in ${DEMOS}
	@${INSTALL_PROGRAM} ${WRKSRC}/${F} ${DESTINY}${EXAMPLESDIR}/
	@${MV} ${WRKSRC}/obj_opt/${F}.* ${WRKSRC}/obj_demos/
.endfor
	@cd ${WRKSRC}/obj_opt && ${AR} rcs libzip-ada.a *.o
	@${MV} ${DESTINY}${PREFIX}/bin/bunzip ${DESTINY}${PREFIX}/bin/debzip2
	@${INSTALL_DATA} ${WRKSRC}/zip_lib/*.ad[sb] \
		${DESTINY}${PREFIX}/include/zip-ada/
	@${INSTALL_DATA} ${WRKSRC}/obj_opt/*.ali \
		${DESTINY}${PREFIX}/lib/zip-ada/
	@${INSTALL_LIB} ${WRKSRC}/obj_opt/*.a ${DESTINY}${PREFIX}/lib/zip-ada/
	@${INSTALL_DATA} ${FILESDIR}/zip-ada.gpr ${DESTINY}${PREFIX}/lib/gnat/

do-install:
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/

.include <bsd.port.mk>
