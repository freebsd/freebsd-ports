# New ports collection makefile for:	gramofile
# Date created:		Fri Jan 28 18:40:38 CET 2000
# Whom:			nox@jelal.kn-bremen.de
#
# $FreeBSD$
#

PORTNAME=	gramofile
PORTVERSION=	1.6P
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://www.opensourcepartners.nl/~costar/gramofile/

PATCH_SITES=	${MASTER_SITE_DEBIAN}
PATCH_SITE_SUBDIR=	pool/main/g/${PORTNAME}
PATCHFILES=	${PORTNAME}_1.6-7.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Audio recording and tick/scratch reduction for e.g. vinyl records

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig11
LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

.if defined(WITH_SWIGDEPS)
RUN_DEPENDS+=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

ALL_TARGET=	gramofile perl-swig
USE_GMAKE=	yes
USE_PERL5=	yes

PERLCOREDIR=	${LOCALBASE}/lib/perl5/${PERL_VERSION}/mach/CORE
MAKE_ARGS+=	PERLCOREDIR=${PERLCOREDIR}

pre-everything::
.if !defined(WITH_SWIGDEPS)
	@${ECHO_MSG} "If you want to use the perl-swig example,"
	@${ECHO_MSG} "${EXAMPLESDIR}/wav2mp3.pl,"
	@${ECHO_MSG} "you need additional depenencies.  You can have this port install them by"
	@${ECHO_MSG} "defining WITH_SWIGDEPS."
.endif

post-patch:
	${RM} ${WRKSRC}/debian/20-warning-fixes.dpatch
	for i in ${WRKSRC}/debian/*.dpatch; do \
		${PATCH} -d ${WRKSRC} `${SED} -n '/^#PATCHOPTIONS:/{s///;p;q;}' $$i` --forward --quiet <$$i ;\
	done
	for i in `${LS} ${FILESDIR}/post-patch-* |${SED} /.orig$$/d`; do \
		${PATCH} -d ${WRKSRC} --forward --quiet <$$i ;\
	done
	${LN} -s ../signpr_cmf3.h ${WRKSRC}/perl-swig
	${LN} -s ../signpr_cmf3.c ${WRKSRC}/perl-swig
	${SED} -e 's,/usr/bin/perl,${PERL},' ${WRKSRC}/perl-swig/examples/wav2mp3.pl >${WRKDIR}/wav2mp3.pl
.for file in bplay.c sndfunc.c
	@${SED} -e 's,machine/soundcard.h,sys/soundcard.h,' < \
		${WRKSRC}/bplaysrc/${file} > ${WRKSRC}/bplaysrc/${file}.new
	@${MV} ${WRKSRC}/bplaysrc/${file}.new ${WRKSRC}/bplaysrc/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gramofile ${WRKSRC}/bplay_gramo ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/perl-swig/Gramofile.pm ${SITE_PERL}/${PERL_ARCH}
	${INSTALL_DATA} ${WRKSRC}/perl-swig/Gramofile.so ${SITE_PERL}/${PERL_ARCH}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/perl-swig/README ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/wav2mp3.pl ${EXAMPLESDIR}
	${LN} -s bplay_gramo ${PREFIX}/bin/brec_gramo

.include <bsd.port.mk>
