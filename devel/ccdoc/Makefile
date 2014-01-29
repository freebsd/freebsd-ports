# Created by: lonewolf@flame.org
# $FreeBSD$

PORTNAME=	ccdoc
PORTVERSION=	0.8r41
CATEGORIES=	devel textproc
MASTER_SITES=	http://ccdoc.sourceforge.net/downloads/
DISTNAME=	src
DIST_SUBDIR=	ccdoc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extracting comments from C++ source and generating HTML

OPTIONS_DEFINE=	DOCS

USES=		perl5

WRKSRC=		${WRKDIR}/${PORTNAME}v${PORTVERSION:S/.//g}/src
MAKEFILE=	mkopt_gcc.mk
ALL_TARGET=	bld
PLIST_FILES=	bin/ccdoc \
		man/man1/ccdoc.1.gz
PORTDOCS=	*

do-configure:
	${REINPLACE_CMD} -e "s:%%PERL%%:${PERL}:" \
		-e "s:%%CXX%%:${CXX}:" \
		-e "s:%%CXXFLAGS%%:${CXXFLAGS}:" \
		-e "s:-pedantic::" \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin_opt_gcc_/ccdoc.exe \
		${STAGEDIR}${PREFIX}/bin/ccdoc
	${INSTALL_MAN} ${WRKSRC}/../doc/htdocs/ccdoc.man ${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC}/../doc \( -name '*.html' -o \
		-name '*.htm' -o \
		-name '*.gif' -o \
		-name '*.txt' -o \
		-name '*.jpg' \) -print | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
