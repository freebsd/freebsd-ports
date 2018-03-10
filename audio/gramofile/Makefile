# Created by: nox@jelal.kn-bremen.de
# $FreeBSD$

PORTNAME=	gramofile
PORTVERSION=	1.6P
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://www.opensourcepartners.nl/~costar/gramofile/

PATCH_SITES=	LOCAL/nox/
PATCHFILES=	${PORTNAME}_1.6-7.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio recording and tick/scratch reduction for e.g. vinyl records

LIB_DEPENDS=	libfftw.so:math/fftw

ALL_TARGET=	gramofile
USES=		alias gmake ncurses perl5
USE_CSTD=	gnu89
MAKE_ARGS=	CC="${CC}" \
		CXX="${CXX}" \
		PERLCOREDIR=${PERLCOREDIR}
CFLAGS+=	-D_WANT_SEMUN

PERLCOREDIR=	${LOCALBASE}/lib/perl5/${PERL_VER}/${PERL_ARCH}/CORE

OPTIONS_DEFINE=	DOCS

post-patch:
	${RM} ${WRKSRC}/debian/20-warning-fixes.dpatch
	for i in ${WRKSRC}/debian/*.dpatch; do \
		${PATCH} -d ${WRKSRC} `${SED} -n '/^#PATCHOPTIONS:/{s///;p;q;}' $$i` --forward --quiet <$$i ;\
	done
	for i in `${LS} ${FILESDIR}/post-patch-* |${SED} /.orig$$/d`; do \
		${PATCH} -d ${WRKSRC} --forward --quiet <$$i ;\
	done
	${REINPLACE_CMD} -e "s@-lncurses@-L${LOCALBASE}/lib -lncurses@g" \
		-e "s|CFLAGS =|CFLAGS +=|" \
		${WRKSRC}/bplaysrc/Makefile
	${REINPLACE_CMD} -e 's,machine/soundcard.h,sys/soundcard.h,' \
		${WRKSRC}/bplaysrc/bplay.c \
		${WRKSRC}/bplaysrc/sndfunc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gramofile ${WRKSRC}/bplay_gramo \
		${STAGEDIR}${PREFIX}/bin
	${LN} -s bplay_gramo ${STAGEDIR}${PREFIX}/bin/brec_gramo

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
