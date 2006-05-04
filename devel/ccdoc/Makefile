# New ports collection makefile for:   ccdoc
# Date created:        9 October 2000
# Whom:                lonewolf@flame.org
#
# $FreeBSD$
#

PORTNAME=	ccdoc
PORTVERSION=	0.8r41
CATEGORIES=	devel textproc
MASTER_SITES=	http://ccdoc.sourceforge.net/downloads/
DISTNAME=	src
DIST_SUBDIR=	ccdoc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extracting comments from C++ source and generating HTML

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}v${PORTVERSION:S/.//g}/src
MAKEFILE=	mkopt_gcc.mk
ALL_TARGET=	bld
MAN1=		ccdoc.1
PLIST_FILES=	bin/ccdoc
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-configure:
	${REINPLACE_CMD} -e "s:%%PERL%%:${PERL}:" \
		-e "s:%%CXX%%:${CXX}:" \
		-e "s:%%CXXFLAGS%%:${CXXFLAGS}:" \
		-e "s:-pedantic::" \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin_opt_gcc_/ccdoc.exe \
		${PREFIX}/bin/ccdoc
	${INSTALL_MAN} ${WRKSRC}/../doc/htdocs/ccdoc.man ${MAN1PREFIX}/man/man1/${MAN1}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${FIND} ${WRKSRC}/../doc \( -name '*.html' -o \
		-name '*.htm' -o \
		-name '*.gif' -o \
		-name '*.txt' -o \
		-name '*.jpg' \) -print | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
