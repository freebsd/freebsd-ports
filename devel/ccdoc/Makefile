# New ports collection makefile for:   ccdoc
# Date created:        9 October 2000
# Whom:                lonewolf@flame.org
#
# $FreeBSD$
#

PORTNAME=	ccdoc
PORTVERSION=	0.7a
CATEGORIES=	devel textproc
MASTER_SITES=	http://www.joelinoff.com/ccdoc/ \
		http://www.flame.org/~lonewolf/distfiles/ \
		http://www.earthmagic.org/FreeBSD/distfiles/
DISTNAME=	ccdoc_v07a_src_taz
EXTRACT_SUFX=	.exe

MAINTAINER=	lonewolf@flame.org

WRKSRC=		${WRKDIR}/ccdoc_v07a
USE_PERL5=	yes

DOCDIR=${PREFIX}/share/doc/ccdoc

pre-patch:
	@${ECHO} "Stripping ^M from all the files..."
	@find ${WRKSRC} -type f | xargs perl -pi -e 's/\r//'

do-build:
	(cd ${WRKSRC}/ccdoc_dev/libjdl/src; ${PERL} mk.pl opt)
	(cd ${WRKSRC}/ccdoc_dev/ccdoc/src; ${PERL} mk.pl opt)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccdoc_dev/ccdoc/bin_freebsd_opt/ccdoc.exe ${PREFIX}/bin/ccdoc

post-install:
	strip ${PREFIX}/bin/ccdoc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/*.gif ${DOCDIR}
	${MKDIR} ${DOCDIR}/images
	${INSTALL_MAN} ${WRKSRC}/doc/images/*.gif ${DOCDIR}/images
	${MKDIR} ${DOCDIR}/autodoc
	${INSTALL_MAN} ${WRKSRC}/doc/autodoc/* ${DOCDIR}/autodoc
.endif

.include <bsd.port.mk>
