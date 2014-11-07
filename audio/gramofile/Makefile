# Created by: nox@jelal.kn-bremen.de
# $FreeBSD$

PORTNAME=	gramofile
PORTVERSION=	1.6P
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	http://www.opensourcepartners.nl/~costar/gramofile/

PATCH_SITES=	${MASTER_SITE_DEBIAN}
PATCH_SITE_SUBDIR=	pool/main/g/${PORTNAME}
PATCHFILES=	${PORTNAME}_1.6-7.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Audio recording and tick/scratch reduction for e.g. vinyl records

LIB_DEPENDS=	libfftw.so:${PORTSDIR}/math/fftw

ALL_TARGET=	gramofile
USES=		gmake perl5
USE_CSTD=	gnu89
MAKE_ARGS+=	CC="${CC}"
MAKE_ARGS+=	CXX="${CXX}"

PERLCOREDIR=	${LOCALBASE}/lib/perl5/${PERL_VER}/${PERL_ARCH}/CORE
MAKE_ARGS+=	PERLCOREDIR=${PERLCOREDIR}

post-patch:
	${RM} ${WRKSRC}/debian/20-warning-fixes.dpatch
	for i in ${WRKSRC}/debian/*.dpatch; do \
		${PATCH} -d ${WRKSRC} `${SED} -n '/^#PATCHOPTIONS:/{s///;p;q;}' $$i` --forward --quiet <$$i ;\
	done
	for i in `${LS} ${FILESDIR}/post-patch-* |${SED} /.orig$$/d`; do \
		${PATCH} -d ${WRKSRC} --forward --quiet <$$i ;\
	done
.for file in bplay.c sndfunc.c
	@${SED} -e 's,machine/soundcard.h,sys/soundcard.h,' < \
		${WRKSRC}/bplaysrc/${file} > ${WRKSRC}/bplaysrc/${file}.new
	@${MV} ${WRKSRC}/bplaysrc/${file}.new ${WRKSRC}/bplaysrc/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gramofile ${WRKSRC}/bplay_gramo \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${LN} -s bplay_gramo ${STAGEDIR}${PREFIX}/bin/brec_gramo

.include <bsd.port.mk>
